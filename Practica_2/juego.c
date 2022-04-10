#include <curses.h>
#include <stdlib.h>
#include <unistd.h>

#define DELAY 300000

int main(int argc, char *argv[])
{
    int rows, cols;
    int x = 0, y = 0;

    //controles

    initscr();
    
    start_color();
    init_pair(1, COLOR_YELLOW, COLOR_GREEN);
    init_pair(2, COLOR_BLACK, COLOR_WHITE);
    init_pair(3,COLOR_WHITE,COLOR_BLUE);
    clear();

    refresh();
    getmaxyx(stdscr, rows, cols);

    WINDOW *window = newwin(rows, cols, 0, 0);
    box(window, '*', '*');

    mvwprintw(window, 15, 40, "Controles:");    
    mvwprintw(window, 20, 40, "Jugador1: A-Z");
    mvwprintw(window, 25, 40, "Jugador2: K-M");
    wrefresh(window);
    
    usleep(DELAY);
    endwin();

    
    //Juego

    int max_y = rows, max_x = cols;
    
    //posicion inicial de la pelota
    int next_x = max_x/2;
    int next_y = max_y/2;
    x = max_x/2;
    y = max_y/2;

    //posicion del jugador 1
    int next_j1_x = 0;
    int next_j1_y = 0;

    //posicion del jugador 2
    int next_j2_x = max_x - 1;
    int next_j2_y = 0;

    //direccion de la pelota
    int direction_x = 1;
    int direction_y = 1;

    initscr();
    noecho();
    curs_set(FALSE);
    
    timeout(50);

    while (1){
        clear();  
        //pintar pelota
        mvprintw(next_y, next_x, "0");
        
        //Pintar jugador 1
        mvprintw(next_j1_y + 1, next_j1_x,"|");
        mvprintw(next_j1_y + 2, next_j1_x,"|");
        mvprintw(next_j1_y + 3, next_j1_x,"|");
        mvprintw(next_j1_y + 4, next_j1_x,"|");
        mvprintw(next_j1_y + 5, next_j1_x,"|");
        mvprintw(next_j1_y + 6, next_j1_x,"|");
        mvprintw(next_j1_y + 7, next_j1_x,"|");
        
        //Pintar jugador 2
        mvprintw(next_j2_y + 1, next_j2_x,"|");
        mvprintw(next_j2_y + 2, next_j2_x,"|");
        mvprintw(next_j2_y + 3, next_j2_x,"|");
        mvprintw(next_j2_y + 4, next_j2_x,"|");
        mvprintw(next_j2_y + 5, next_j2_x,"|");
        mvprintw(next_j2_y + 6, next_j2_x,"|");
        mvprintw(next_j2_y + 7, next_j2_x,"|");

        refresh();
        

        //Movimiento de la pelota
        next_y = y + direction_y;
        next_x = x + direction_x;
    

        if (next_y >= max_y || next_y <= 0)
        {
            direction_y *= -1;
        }else{
            y += direction_y;
        }

        //Calculo del movimiento pelota eje x
        if (next_x == next_j2_x && (next_y <= next_j2_y + 4 && next_y >= next_j2_y)){
            direction_x *= -1;
        } 
        else if (next_x == next_j1_x && (next_y <= next_j1_y + 4 && next_y >= next_j1_y)){
            direction_x *= -1;
        }else{
            x += direction_x;
        }

        switch (getch()){
            //Movimiento jugador 1
            case 'a':
                if (next_j1_y >= 2)
                    next_j1_y -= 1;
                break;
            case 'z':
                if (next_j1_y + 3 <= max_y - 3)
                    next_j1_y += 1;
                break;
            //Movimiento jugador 2
            case 'k':
                if (next_j2_y >= 2)
                    next_j2_y -= 1;
                break;
            case 'm':
                if (next_j2_y + 3 <= max_y - 3)
                    next_j2_y += 1;
                break;
            default:
                break;
        }
    }
    endwin();
}
