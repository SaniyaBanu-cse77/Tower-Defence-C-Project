#include <stdio.h>

// ----- CONSTANTS -----
#define TOTAL_ENEMIES 3
#define BASE_POSITION 10
#define TOWER_POSITION 5

// ----- STRUCTURE -----
struct Enemy {
    int position;
    int health;
    int alive;
};

// ----- MAIN FUNCTION -----
int main() {

    struct Enemy enemies[TOTAL_ENEMIES];
    int baseHealth = 100;
    int i, step = 0;

    // Initialize enemies
    for (i = 0; i < TOTAL_ENEMIES; i++) {
        enemies[i].position = 0;
        enemies[i].health = 50;
        enemies[i].alive = 1;
    }

    printf("=== Tower Defence Game Started ===\n");

    // Game loop
    while (baseHealth > 0) {

        step++;
        printf("\n--- Step %d ---\n", step);

        for (i = 0; i < TOTAL_ENEMIES; i++) {

            if (enemies[i].alive == 1) {

                // Enemy moves forward
                enemies[i].position++;
                printf("Enemy %d moved to position %d\n", i + 1, enemies[i].position);

                // Tower attacks continuously after position 5
                if (enemies[i].position >= TOWER_POSITION && enemies[i].health > 0) {
                    enemies[i].health -= 20;
                    printf("Tower attacked Enemy %d! Health = %d\n",
                           i + 1, enemies[i].health);
                }

                // Enemy destroyed
                if (enemies[i].health <= 0) {
                    enemies[i].alive = 0;
                    printf("Enemy %d destroyed by tower!\n", i + 1);
                }

                // Enemy reaches base
                else if (enemies[i].position >= BASE_POSITION) {
                    baseHealth -= 20;
                    enemies[i].alive = 0;
                    printf("Enemy %d reached base!\n", i + 1);
                    printf("Base health = %d\n", baseHealth);
                }
            }
        }

        // Check win condition
        int allDead = 1;
        for (i = 0; i < TOTAL_ENEMIES; i++) {
            if (enemies[i].alive == 1)
                allDead = 0;
        }

        if (allDead == 1) {
            printf("\nAll enemies eliminated.\n");
            printf("YOU WIN!\n");
            break;
        }
    }

    // Lose condition
    if (baseHealth <= 0) {
        printf("\nBase destroyed.\n");
        printf("GAME OVER!\n");
    }

    return 0;
}
