
    algorithm GreyWolfOptimizer(max_iterations):
    // INPUT
    //    n = the number of wolves in the pack
    //    max_iterations = the maximum number of iterations for the optimization process
    // OUTPUT
    //    X_alpha = the best found agent
    X <- Initialize the grey wolf population with n agents
    Initialize a, A, and C
    Calculate the fitness of each search agent
    X_alpha <- the best search agent
    X_beta <- the second best search agent
    X_delta <- the third best search agent

    t <- 0
    while t < max_iterations:
        for each search agent in X:
            Randomly initialize r1 and r2
            Update the position of the current search agent by the equation (7)

        Update a, A, and C

        Calculate the fitness of all search agents

        Update X_alpha, X_beta, and X_delta

        t <- t + 1

    return X_alpha
