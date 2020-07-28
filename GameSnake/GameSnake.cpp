#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

int posX = 4, posY = 4; //Начальные координаты объекта
const int fieldWidth = 10, fieldHeight = 10; //Размер игрового поля
char mas[fieldWidth][fieldHeight]; //Массив, используемый для создания игрового поля
char food = 'R'; //Символ "еды"
int x = 0, y = 0; //Переменные для координат еды

//Генерация игрового поля
void gameFieldCreat() {
    //Здесь делаю рамку, ограничивающую игровую область (размер задается выше)
    for (int i = 0; i < fieldWidth; i++) {
        for (int j = 0; j < fieldHeight; j++) {
            if (i == 0 || i == 9 || j == 0 || j == 9)
                mas[i][j] = '*'; //Границы обознаены символом звездоки
            else
                mas[i][j] = ' '; //Игровая область пустая
        }
    }
}

//Печать массива (игрового поля)
void gameFieldPrint() {
    system("cls");
    for (int i = 0; i < fieldWidth; i++) {
        for (int j = 0; j < fieldHeight; j++) {
            cout << mas[i][j];
        }
        cout << endl;
    }
}

//Создание объекта в массиве (символ ASCII)
void someObject() {    
    mas[posY][posX] = 15;
}

//Управление объектом
void objectControl() {
        char c = _getch();

        //a - влево
        if (c == 'a') {
            mas[posX][posY] = ' ';
            posY--;
            mas[posX][posY] = 15;
        }
        //d - вправо
        if (c == 'd') {
            mas[posX][posY] = ' ';
            posY++;
            mas[posX][posY] = 15;
        }

        //s - вниз
        if (c == 's') {
            mas[posX][posY] = ' ';
            posX++;
            mas[posX][posY] = 15;
        }

        //w - вверх
        if (c == 'w') {
            mas[posX][posY] = ' ';
            posX--;
            mas[posX][posY] = 15;
        }
}

//Генерация "еды"
void foodGenerator() {
        //Генерация координат
        x = 0 + rand() % (fieldWidth - 2) + 1;
        y = 0 + rand() % (fieldHeight - 2) + 1;

        mas[x][y] = food; //Присвоение "еды" ячейке массива
}

int main()
{
    gameFieldCreat(); //Создаем игровое поле
    someObject(); //Создаем объект
    foodGenerator(); //Генерация еды

    do {
        gameFieldPrint(); //Рисуем игровое поле с объектом

        objectControl(); //Вызываем функцию управления

        //Условие генерации новой еды - если точка встала на клетку с едой
        if (posX == x && posY == y) {
            foodGenerator();
        }
        
        //Проверка на выход за границы
        if (posX <= 0 || posX >= fieldWidth - 1 || posY <= 0 || posY >= fieldHeight - 1) {
            posX = 0;
        }

    } while (posX != 0); 

    cout << "game over" << endl;    

    system("pause");
    return 0;
}
