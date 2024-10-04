# Grey Wolf Optimization (GWO) Search Algorithm with CodeQL & Dependabot Integration

### Table of Contents

1. Introduction
2. Features
3. Grey Wolf Optimizer (GWO) Algorithm
    - Key Concepts
    - Advantages
4. Installation
5. Usage
6. CodeQL and Security Integration
    - CodeQL Analysis
    - Security Policy
7. Dependabot Integration
8. Contributing
9. License
10. Acknowledgments
![image](https://github.com/user-attachments/assets/e8774d7c-e185-4020-a315-be4301e38c2f)


---

## Introduction

Grey Wolf Optimization (GWO) is a metaheuristic optimization algorithm that mimics the hunting behavior and social hierarchy of grey wolves. This project implements a **search algorithm** using GWO to find a target within a doubly linked list of nodes. The repository integrates **CodeQL** for static code analysis and **Dependabot** for automated dependency management.

---

## Features

- **Grey Wolf Optimizer (GWO)**: Simulates the natural hunting behavior of grey wolves to search for a target in a list.
- **CodeQL Analysis**: Ensures code quality and security using GitHub’s CodeQL engine.
- **Dependabot Integration**: Automatically updates dependencies, keeping the project secure and up to date.
- **Security Policy**: A detailed process for reporting vulnerabilities.

---

## Grey Wolf Optimizer (GWO) Algorithm

### Key Concepts

1. **Social Hierarchy**:
   - **Alpha (α)**: The leader, representing the best solution.
   - **Beta (β)**: The second-best solution, supporting the alpha.
   - **Delta (δ)**: The third-best solution, subordinate to the alpha and beta.
   - **Omega (ω)**: The rest of the pack, which follow the leading wolves.

2. **Hunting Phases**:
   - **Encircling Prey**: Wolves update their positions based on the best solutions (alpha, beta, delta).
   - **Hunting**: Wolves adjust their positions to converge towards the target.
   - **Attacking the Prey**: Wolves gradually close in on the target, reducing the search space.

### Advantages

- **Simple Implementation**: Easy to code with few parameters.
- **Effective Search**: Balances global exploration and local exploitation.
- **Fewer Parameters**: Requires fewer settings compared to other optimization algorithms.

---

## Installation

### Prerequisites

- **C/C++ compiler (GCC or Clang)**: The project uses C/C++ for implementation.
- **Git**: For cloning the repository.
- **GitHub Actions**: If you want to run the automated CI/CD pipeline.

### Steps

1. Clone the repository:
    ```bash
    git clone https://github.com/arnav108276/Search-Optimization-in-linked-list.git
    cd Search-Optimization-in-linked-list
    ```

2. Compile the project:
    ```bash
    gcc fitness.c -o gwo_search
    ```

3. Run the program:
    ```bash
    ./gwo_search
    ```

---

## Usage

1. **Running the Algorithm**:
    - Modify the target and node list in `fitness.c` to match your specific search space.
    - Compile and execute the program as described in the Installation section.

---

## CodeQL and Security Integration

### CodeQL Analysis

This project uses GitHub Actions to automate the analysis of code with CodeQL. This helps in identifying potential security vulnerabilities and ensures high code quality. The analysis runs automatically on each push and pull request.The workflow runs everyday at night 00:30am and everytime a commit is been made and checks for any vunerabilities in code
![image](https://github.com/user-attachments/assets/8abed6da-38e9-4fc7-b2d2-73b9cbf147c0)
(Uploaded on October3)


### Security Policy

| Tasks                                   | Allowed          |
|-----------------------------------------|------------------|
| Commit to individual branch             | :white_check_mark: |
| Commit to main branch directly          | :x:              |
| Propose issues                          | :white_check_mark: |
| Code analysis                           | :white_check_mark: |
| Public License                          | :white_check_mark: |


## Dependabot Integration

This project is configured with Dependabot to keep dependencies up to date. The configuration file is located at `.github/dependabot.yml`, which specifies:

- Package ecosystems to update.
- The directory where package manifests are located.
- The schedule for updates (weekly).

---

## Contributing

We welcome contributions to improve the project. Please follow these guidelines:

1. Fork the repository.
2. Create a new branch for your feature or bug fix.
3. Commit your changes.
4. Push your branch and open a pull request.

---

## License

This project is licensed under the MIT License. See the LICENSE file for more information.

---

## Acknowledgments

- **GWO Authors**: Acknowledgment to Mirjalili et al. for introducing the Grey Wolf Optimization algorithm.
- **GitHub**: For providing the tools and infrastructure to support this project.
