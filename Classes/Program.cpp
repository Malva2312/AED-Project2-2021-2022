//
// Created by asus on 25/01/2022.
//

#include "Program.h"
#include "../UI/Menu.h"

Program::Program() {
    Menu newMenu = Menu(this);
    this-> menu = &newMenu;
    initializeProgram();
}

/**
 * Initializes every data necessary for executing tasks and the UI.
 *
 */
void Program::initializeProgram() {
    this->menu->programMenu();
}

void Program::setUserLocation(Coordinates coordinates) {
    this->userCoordinates = coordinates;
}

Coordinates Program::getUserLocation() {
    return this->userCoordinates;
}