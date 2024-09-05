// Fitness function for GWO
double fitness(Node* wolf, int target) {
    return abs(wolf->data - target);
}
