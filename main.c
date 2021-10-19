//
//  main.c
//
//
//  Created by Jose Carlos Garcia Mendizabal on 18/08/21.
//


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <uuid/uuid.h>

#define STRING_LENGTH 30 // Length of a word
#define MAX_SHIPS_OWERSHIP 10 // Length of a word
#define UUID_SIZE 37 // Length of a UUID

typedef enum {arponero, cocinero, vigia, capitan} crewRole;

typedef struct {
    char firstName[STRING_LENGTH]; // nombre de tripulante
    char lastName[STRING_LENGTH]; // apellido de tripulante
    int age; // edad de tripulante
} Owner;

typedef struct {
    char shipID[UUID_SIZE]; // identificador de embarcacion a la que pertenece el tripulante
    char firstName[STRING_LENGTH]; // nombre de tripulante
    char lastName[STRING_LENGTH]; // apellido de tripulante
    int age; // edad de tripulante
    char role[STRING_LENGTH]; // rol que desempeña dentro de la tripulación
} CrewMember;

typedef struct {
    char ID[UUID_SIZE]; // identificador de embarcacion
    char name[STRING_LENGTH]; // nombre de embarcacion
    float length; // eslora de embarcacion
    float beam; // manga de embarcacion
    int maxCrewSize; // número máximo de tripulantes dentro de embarcacion
    Owner shipOwner; // dueño de la embarcación
    CrewMember crew[]; // dueño de la embarcación
} Ship;

int main(int argc, const char * argv[]) {
    char menuChoice;
    int numberOfShips = 0;
    int extraShips = 0;
    Ship* port = NULL;
    Ship* auxPort = NULL;
    
    printf("Welcome to Joselo Port \n");
    printf("How many ships are you going to add? : ");
    scanf("%d", &numberOfShips);
    
    port = (Ship*) malloc(sizeof(Ship) * numberOfShips);
    Ship* finalPort = port + numberOfShips;
    
    for (auxPort = port; auxPort < finalPort; ++auxPort) {
        uuid_t binUUID;
        uuid_generate_random(binUUID);
        char *UUID = malloc(UUID_SIZE);
        uuid_unparse(binUUID, UUID);
        strcpy(auxPort->ID, UUID);
        printf("\nShip Name: ");
        scanf("%s", auxPort->name);
        printf(" Ship Length: ");
        scanf("%f", &auxPort->length);
        printf(" Ship Beam: ");
        scanf("%f", &auxPort->beam);
        printf(" Ship Max Crew Size: ");
        scanf("%d", &auxPort->maxCrewSize);
        printf(" Owner First Name: ");
        scanf("%s", auxPort->shipOwner.firstName);
        printf(" Owner Last Name: ");
        scanf("%s", auxPort->shipOwner.lastName);
        printf(" Owner Age: ");
        scanf("%d", &auxPort->shipOwner.age);
        for (int i = 0; i < auxPort->maxCrewSize; i++) {
            printf(" Member [%d] First Name: ", i);
            scanf("%s", auxPort->crew[i].firstName);
            printf(" Member [%d] Last Name: ", i);
            scanf("%s", auxPort->crew[i].lastName);
            printf(" Member [%d] Age: ", i);
            scanf("%d", &auxPort->crew[i].age);
        }
    }
    
    do {
        printf("\n1) Add more ships \n");
        printf("2) Show ships \n");
        printf("3) Exit \n");
        printf("Option: ");
        fflush(stdin);
        menuChoice = getchar();
        while (menuChoice == '\n') {
            menuChoice = getchar();
        }
        switch (menuChoice) {
            case '1':
                printf("\nNumber of extra ships: ");
                scanf("%d", &extraShips);
                if (extraShips > 0) {
                    port = (Ship*) realloc(port, sizeof(Ship) * (numberOfShips + extraShips));
                    finalPort = port + numberOfShips + extraShips;
                    for (auxPort = port + numberOfShips; auxPort < finalPort; ++auxPort) {
                        uuid_t binUUID;
                        uuid_generate_random(binUUID);
                        char *UUID = malloc(UUID_SIZE);
                        uuid_unparse(binUUID, UUID);
                        strcpy(auxPort->ID, UUID);
                        printf("\ns Ship Name: ");
                        scanf("%s", auxPort->name);
                        printf(" Ship Length: ");
                        scanf("%f", &auxPort->length);
                        printf(" Ship Beam: ");
                        scanf("%f", &auxPort->beam);
                        printf(" Ship Max Crew Size: ");
                        scanf("%d", &auxPort->maxCrewSize);
                        printf(" Owner First Name: ");
                        scanf("%s", auxPort->shipOwner.firstName);
                        printf(" Owner Last Name: ");
                        scanf("%s", auxPort->shipOwner.lastName);
                        printf(" Owner Age: ");
                        scanf("%d", &auxPort->shipOwner.age);
                    }
                }
                break;
            case '2':
                printf("\nShips: \n");
                for (auxPort = port; auxPort < finalPort; ++auxPort) {
                    printf(" Ship ID: %s \n", auxPort->ID);
                    printf(" Ship Name: %s \n", auxPort->name);
                    printf(" Ship Max Crew Size: %d \n", auxPort->maxCrewSize);
                    printf(" Ship Owner First Name: %s \n", auxPort->shipOwner.firstName);
                    printf(" Ship Owner Last Name: %s \n", auxPort->shipOwner.lastName);
                    for (int i = 0; i < auxPort->maxCrewSize; i++) {
                        printf(" Member [%d] First Name: %s \n", i, auxPort->crew[i].firstName);
                        printf(" Member [%d] Last Name: %s \n", i, auxPort->crew[i].lastName);
                        printf(" Member [%d] Age: %d \n", i, auxPort->crew[i].age);
                    }
                    printf("-");
                }
                break;
            default:
                break;
        }
    } while (menuChoice != '3');
        
    free(port);
    
    return 0;
}
