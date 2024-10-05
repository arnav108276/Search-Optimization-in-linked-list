# -*- coding: utf-8 -*-
"""
Created on Mon May 16 00:27:50 2016

@author: Hossam Faris
"""

import random
import numpy as np
import time

class solution:
    def __init__(self):
        self.best = 0
        self.bestIndividual = []
        self.convergence = []
        self.optimizer = ""
        self.objfname = ""
        self.startTime = 0
        self.endTime = 0
        self.executionTime = 0

def GWO(objf, lb, ub, dim, SearchAgents_no, Max_iter):
    # Initialize alpha, beta, and delta positions
    Alpha_pos = np.zeros(dim)
    Alpha_score = float("inf")

    Beta_pos = np.zeros(dim)
    Beta_score = float("inf")

    Delta_pos = np.zeros(dim)
    Delta_score = float("inf")

    if not isinstance(lb, list):
        lb = [lb] * dim
    if not isinstance(ub, list):
        ub = [ub] * dim

    # Initialize positions of search agents
    Positions = np.zeros((SearchAgents_no, dim))
    for i in range(dim):
        Positions[:, i] = (
            np.random.uniform(0, 1, SearchAgents_no) * (ub[i] - lb[i]) + lb[i]
        )

    Convergence_curve = np.zeros(Max_iter)
    s = solution()

    # Loop counter
    print('GWO is optimizing "' + objf.__name__ + '"')

    timerStart = time.time()
    s.startTime = time.strftime("%Y-%m-%d-%H-%M-%S")

    # Main loop
    for l in range(Max_iter):
        for i in range(SearchAgents_no):
            # Return search agents that go beyond the boundaries of the search space
            for j in range(dim):
                Positions[i, j] = np.clip(Positions[i, j], lb[j], ub[j])

            # Calculate objective function for each search agent
            fitness = objf(Positions[i, :])

            # Update Alpha, Beta, and Delta
            if fitness < Alpha_score:
                Delta_score = Beta_score  # Update delta
                Delta_pos = Beta_pos.copy()
                Beta_score = Alpha_score  # Update beta
                Beta_pos = Alpha_pos.copy()
                Alpha_score = fitness
                Alpha_pos = Positions[i, :].copy()

            if Alpha_score < fitness < Beta_score:
                Delta_score = Beta_score  # Update delta
                Delta_pos = Beta_pos.copy()
                Beta_score = fitness  # Update beta
                Beta_pos = Positions[i, :].copy()

            if Beta_score < fitness < Delta_score:
                Delta_score = fitness  # Update delta
                Delta_pos = Positions[i, :].copy()

        a = 2 - l * (2 / Max_iter)  # Decreases linearly from 2 to 0

        # Update the position of search agents including omegas
        for i in range(SearchAgents_no):
            for j in range(dim):
                r1, r2 = random.random(), random.random()

                A1 = 2 * a * r1 - a
                C1 = 2 * r2

                D_alpha = abs(C1 * Alpha_pos[j] - Positions[i, j])
                X1 = Alpha_pos[j] - A1 * D_alpha

                r1, r2 = random.random(), random.random()

                A2 = 2 * a * r1 - a
                C2 = 2 * r2

                D_beta = abs(C2 * Beta_pos[j] - Positions[i, j])
                X2 = Beta_pos[j] - A2 * D_beta

                r1, r2 = random.random(), random.random()

                A3 = 2 * a * r1 - a
                C3 = 2 * r2

                D_delta = abs(C3 * Delta_pos[j] - Positions[i, j])
                X3 = Delta_pos[j] - A3 * D_delta

                Positions[i, j] = (X1 + X2 + X3) / 3  # Update position

        Convergence_curve[l] = Alpha_score

        if l % 1 == 0:
            print("At iteration " + str(l) + " the best fitness is " + str(Alpha_score))

    timerEnd = time.time()
    s.endTime = time.strftime("%Y-%m-%d-%H-%M-%S")
    s.executionTime = timerEnd - timerStart
    s.convergence = Convergence_curve
    s.optimizer = "GWO"
    s.bestIndividual = Alpha_pos
    s.objfname = objf.__name__

    return s

# Sample objective function
def objective_function(x):
    return sum(x**2)  # Example: minimize the sum of squares

# Define parameters
lb = [-10] * 30  # Lower bounds
ub = [10] * 30   # Upper bounds
dim = 30         # Dimension of the search space
SearchAgents_no = 5  # Number of search agents
Max_iter = 100    # Maximum iterations

# Run the GWO algorithm
result = GWO(objective_function, lb, ub, dim, SearchAgents_no, Max_iter)

# Output results
print("Best Fitness:", result.best)
print("Best Individual:", result.bestIndividual)
print("Convergence Curve:", result.convergence)
