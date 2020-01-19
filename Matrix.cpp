//
// Created by omer on 15/01/2020.
//

#include "Matrix.h"
Matrix::Matrix(int rows, int columns, vector<vector<double>> matrix, State<Cell> *initial, State<Cell> *goal) {
    this->rows = rows;
    this->columns = columns;
    this->matrix = matrix;
    this->initialState = initial;
    this->goalState = goal;
}

State<Cell>* Matrix:: getInitialState() {
    return this->initialState;
}
bool Matrix:: isGoalState(State<Cell> *state) {
    return (goalState->operator==(state));
}
vector<State<Cell>*> Matrix:: getAllPossibleStates(State<Cell> *state) {
    vector<State<Cell>*> adjList;
    //gets i,j - location on the matrix
    int row = state->getStateObj().getRow();
    int column = state->getStateObj().getColumn();
    //creates all thw "neighbors" cells
    State<Cell> *s1 = new State<Cell> (Cell(row-1, column));
    State<Cell> *s2 = new State<Cell> (Cell(row+1, column));
    State<Cell> *s3 = new State<Cell> (Cell(row, column-1));
    State<Cell> *s4 = new State<Cell> (Cell(row, column+1));
    //push them to the list
    adjList.push_back(s1);
    adjList.push_back(s2);
    adjList.push_back(s3);
    adjList.push_back(s4);

    for (int i = 0; i < 4; i++) {
        State<Cell> *checker = adjList.back();
        adjList.pop_back();
        if (checker->getStateObj().getRow() >= 0 && checker->getStateObj().getRow() <= rows-1 && checker->getStateObj().getColumn() >= 0 && checker->getStateObj().getColumn() <= columns-1) {
            adjList.insert(adjList.begin(), checker);
        }
    }
    return adjList;
}
double Matrix::getStateValue(State<Cell> *state) {
    return matrix[state->getStateObj().getRow()][state->getStateObj().getColumn()];
}

void Matrix::setStateValue(State<Cell> *state, double val) {
    matrix[state->getStateObj().getRow()][state->getStateObj().getColumn()] = val;
}