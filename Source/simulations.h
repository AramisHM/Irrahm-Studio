extern double E1, E2, Q1, Q2, R1, R2, ER;

/* Calculates the distance.  */
double FFDistance(IMeshSceneNode *a, IMeshSceneNode *b);

/* Calculates and display in somewere the results of the forces and its propeties. */
void CalculateForceField();

/* Calculates the E.  */
double FFE(double Q, double rad);

/* Cinematica. */
void SQL();
void SLH();
void SLO();