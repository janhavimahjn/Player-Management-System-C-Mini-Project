#include <stdio.h>
#include <string.h>
#define MAX_PLAYERS 100

typedef struct {
    int jerseyNumber;
    char name[50];
    int runs;
    int wickets;
    int matches;
} Player;

Player players[MAX_PLAYERS];
int playerCount = 0;

void addPlayer();
void removePlayer();
void searchPlayer();
void updatePlayerData();
void displaySortedPlayers();
void displayAllPlayers();
void displayTopPlayers();

int main() {
    int choice;

    do {
        printf("\n--- Player Management System ---\n");
        printf("1. Add Player\n");
        printf("2. Remove Player\n");
        printf("3. Search Player\n");
        printf("4. Update Player Data\n");
        printf("5. Display Sorted Players\n");
        printf("6. Display All Players\n");
        printf("7. Display Top 3 Players (Runs and Wickets)\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addPlayer(); break;
            case 2: removePlayer(); break;
            case 3: searchPlayer(); break;
            case 4: updatePlayerData(); break;
            case 5: displaySortedPlayers(); break;
            case 6: displayAllPlayers(); break;
            case 7: displayTopPlayers(); break;
            case 8: printf("Exiting the program.\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 8);

    return 0;
}

void addPlayer() {
    if (playerCount >= MAX_PLAYERS) {
        printf("Player database is full!\n");
        return;
    }

    Player newPlayer;
    printf("Enter Jersey Number: ");
    scanf("%d", &newPlayer.jerseyNumber);
    printf("Enter Name: ");
    scanf("%s", newPlayer.name);
    printf("Enter Runs: ");
    scanf("%d", &newPlayer.runs);
    printf("Enter Wickets: ");
    scanf("%d", &newPlayer.wickets);
    printf("Enter Matches Played: ");
    scanf("%d", &newPlayer.matches);

    players[playerCount++] = newPlayer;
    printf("Player added successfully!\n");
}

void removePlayer() {
    int jerseyNumber, i, found = 0;
    printf("Enter Jersey Number of the player to remove: ");
    scanf("%d", &jerseyNumber);

    for (i = 0; i < playerCount; i++) {
        if (players[i].jerseyNumber == jerseyNumber) {
            found = 1;
            for (int j = i; j < playerCount - 1; j++) {
                players[j] = players[j + 1];
            }
            playerCount--;
            printf("Player removed successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Player with Jersey Number %d not found.\n", jerseyNumber);
    }
}

void searchPlayer() {
    int jerseyNumber;
    char name[50];
    int choice, found = 0;

    printf("Search by: 1. Jersey Number 2. Name\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter Jersey Number: ");
        scanf("%d", &jerseyNumber);
        for (int i = 0; i < playerCount; i++) {
            if (players[i].jerseyNumber == jerseyNumber) {
                printf("Player Found:\n");
                 printf("----------------------------------------------\n");
                printf("| %-15s | %-20s | %-10s | %-10s | %-10s |\n", "Jersey Number", "Name", "Runs", "Wickets", "Matches");
                 printf("----------------------------------------------\n");
                printf("| %-15d | %-20s | %-10d | %-10d | %-10d |\n",
                       players[i].jerseyNumber, players[i].name, players[i].runs, players[i].wickets, players[i].matches);
                       
                found = 1;
                break;
            }
        }
    } else if (choice == 2) {
        printf("Enter Name: ");
        scanf("%s", name);
        for (int i = 0; i < playerCount; i++) {
            if (strcmp(players[i].name, name) == 0) {
                printf("Player Found:\n");
                 printf("----------------------------------------------\n");
                printf("| %-15s | %-20s | %-10s | %-10s | %-10s |\n", "Jersey Number", "Name", "Runs", "Wickets", "Matches");
                 printf("----------------------------------------------\n");
                printf("| %-15d | %-20s | %-10d | %-10d | %-10d |\n",
                       players[i].jerseyNumber, players[i].name, players[i].runs, players[i].wickets, players[i].matches);
                found = 1;
                break;
            }
        }
    }

    if (!found) {
        printf("Player not found.\n");
    }
}

void updatePlayerData() {
    int jerseyNumber, found = 0;
    printf("Enter Jersey Number of the player to update: ");
    scanf("%d", &jerseyNumber);

    for (int i = 0; i < playerCount; i++) {
        if (players[i].jerseyNumber == jerseyNumber) {
            printf("Enter new Runs: ");
            scanf("%d", &players[i].runs);
            printf("Enter new Wickets: ");
            scanf("%d", &players[i].wickets);
            printf("Enter new Matches Played: ");
            scanf("%d", &players[i].matches);

            printf("Player data updated successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Player with Jersey Number %d not found.\n", jerseyNumber);
    }
}

void displaySortedPlayers() {
    int choice;
    printf("Sort by: 1. Runs (Descending) 2. Wickets (Descending)\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    for (int i = 0; i < playerCount - 1; i++) {
        for (int j = i + 1; j < playerCount; j++) {
            if ((choice == 1 && players[i].runs < players[j].runs) ||
                (choice == 2 && players[i].wickets < players[j].wickets)) {
                Player temp = players[i];
                players[i] = players[j];
                players[j] = temp;
            }
        }
    }

    printf("\nSorted Players:\n");
     printf("---------------------------------------------------------------------------------\n");
    printf("| %-15s | %-20s | %-10s | %-10s | %-10s |\n", "Jersey Number", "Name", "Runs", "Wickets", "Matches");
    printf("----------------------------------------------------------------------------------\n");
    for (int i = 0; i < playerCount; i++) {
        printf("| %-15d | %-20s | %-10d | %-10d | %-10d |\n",
               players[i].jerseyNumber, players[i].name, players[i].runs, players[i].wickets, players[i].matches);
    }
}

void displayAllPlayers() {
    if (playerCount == 0) {
        printf("No players in the database.\n");
        return;
    }

    printf("\nAll Players:\n");
     printf("---------------------------------------------------------------------------------\n");
    printf("| %-15s | %-20s | %-10s | %-10s | %-10s |\n", "Jersey Number", "Name", "Runs", "Wickets", "Matches");
    printf("----------------------------------------------------------------------------------\n");
    for (int i = 0; i < playerCount; i++) {
        printf("| %-15d | %-20s | %-10d | %-10d | %-10d |\n",
               players[i].jerseyNumber, players[i].name, players[i].runs, players[i].wickets, players[i].matches);
    }
}

void displayTopPlayers() {
    Player topRuns[3] = {0}, topWickets[3] = {0};

    for (int i = 0; i < playerCount; i++) {
        for (int j = 0; j < 3; j++) {
            if (players[i].runs > topRuns[j].runs) {
                for (int k = 2; k > j; k--) {
                    topRuns[k] = topRuns[k - 1];
                }
                topRuns[j] = players[i];
                break;
            }
        }

        for (int j = 0; j < 3; j++) {
            if (players[i].wickets > topWickets[j].wickets) {
                for (int k = 2; k > j; k--) {
                    topWickets[k] = topWickets[k - 1];
                }
                topWickets[j] = players[i];
                break;
            }
        }
    }

    printf("\nTop 3 Players by Runs:\n");
     printf("----------------------------------------------\n");
    printf("| %-15s | %-20s | %-10s |\n", "Jersey Number", "Name", "Runs");
    printf("----------------------------------------------\n");
    for (int i = 0; i < 3 && topRuns[i].runs > 0; i++) {
        printf("| %-15d | %-20s | %-10d |\n",
               topRuns[i].jerseyNumber, topRuns[i].name, topRuns[i].runs);
    }

    printf("\nTop 3 Players by Wickets:\n");
    printf("----------------------------------------------\n");
    printf("| %-15s | %-20s | %-10s |\n", "Jersey Number", "Name", "Wickets");
    printf("----------------------------------------------\n");
    for (int i = 0; i < 3 && topWickets[i].wickets > 0; i++) {
        printf("| %-15d | %-20s | %-10d |\n",
               topWickets[i].jerseyNumber, topWickets[i].name, topWickets[i].wickets);
    }
}

