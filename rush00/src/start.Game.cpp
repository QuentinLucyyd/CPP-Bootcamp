/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.Game.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 21:30:39 by root              #+#    #+#             */
/*   Updated: 2018/06/10 06:46:04 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/GameEntity.class.hpp"
#include "../headers/Player.class.hpp"
#include "../headers/Enemy.class.hpp"
#include "../headers/EnemyHorde.class.hpp"
#include "../headers/Star.class.hpp"
#include "../headers/Bullet.class.hpp"

#include <string>

void    moveLeft(WINDOW *win, Player &_player) {
    int curX = _player.getX() - 2;
    if (curX > 0) {
        _player.notTail(win,5);
        _player.setX(curX);
        mvwprintw(win,_player.getY(), _player.getX(), _player.getDisplay().c_str());
        wrefresh(win);
    }
}

void    moveRight(WINDOW *win, Player &_player, int max_x) {
    int curX = _player.getX() + 2;
            if (curX < max_x - 5) {
                _player.notTail(win,5);
                _player.setX(curX);
                mvwprintw(win,_player.getY(), _player.getX(), _player.getDisplay().c_str());
                wrefresh(win);
            }
}

void    moveUp(WINDOW *win, Player &_player) {
    int curY = _player.getY() - 2;
            if (curY - 1 > 0) {
                _player.notTail(win,5);
                _player.setY(curY);
                mvwprintw(win,_player.getY(), _player.getX(), _player.getDisplay().c_str());
                wrefresh(win);
            }
}

void    moveDown(WINDOW *win, Player &_player, int max_y) {
    int curY = _player.getY() + 2;
            if (curY < max_y) {
                _player.notTail(win,5);
                _player.setY(curY);
                mvwprintw(win,_player.getY(), _player.getX(), _player.getDisplay().c_str());
                wrefresh(win);
            }
} 

int    checkCollision(WINDOW *win, Player &_player) {
    chtype next = mvwinch(win, _player.getY() - 1, _player.getX() + 2);
    char n = (next & A_CHARTEXT);
    if (n == ' '){
        mvwaddstr(win, 5, 5, "No Collission");
        return 1;
    } else {
        if (n != '.' && n != '*' && n != '+'){
            if (_player.getHP() == 0) {
                _player.notTail(win, 5);
            } else {
                _player.takeDamage(1);
            }
        }
    }
}

void    startGame(WINDOW *win, WINDOW *score) {
    int gameloop = 1;
    int Frame = 0;
    Player  _def;
    Player& _player(_def);
    Enemy _defenemy;
    Enemy& _enemy(_defenemy);
    Enemy _enemy2;
    Enemy *Enemies = new Enemy[5];
    nodelay(win, true);
    int     max_y;
    int     max_x;
    int     keyPressed;
    wclear(win);
    getmaxyx(win, max_y, max_x);
    _player.setY(max_y-2);
    _player.setX(round(max_x/2)-2);
    Star    *_stars = new Star[50];
    EnemyHorde _enemies(10, max_x);
    std::cout << "m/" << max_x << "y/" << max_y;
    box(win, '+', '+');
    mvwprintw(win,_player.getY(), _player.getX(), _player.getDisplay().c_str());
    keypad(win, TRUE);
     _enemy.setX(_enemy.randomXValue(max_x));
    // _enemy2.setX(_enemy2.randomXValue(max_x));
    //mvwprintw(win, 1, 1, std::to_string(_enemy.getX()).c_str());
    //mvwprintw(win, 5, 1, std::to_string(_enemy2.getX()).c_str());
    int p = -1;

    while (++p < 10) {
        int randomx = rand() % max_x - 1;
        int randomy = rand() % max_y;
        Enemies[p].setX(randomx);
        Enemies[p].setY(randomy);
    }
    int st = -1;
    while(++st < 50) {
        int randomx = rand() % max_x -1;
        int randomy = rand() % max_y -1;
        _stars[st].setX(randomx);
        _stars[st].setY(randomy);
    }
    while(gameloop == 1) {
        int st = -1;
        while(++st < 50) {
            mvwaddch(win, _stars[st].getY(), _stars[st].getX(), ' ');
            if (_stars[st].getY() > max_y) {
                _stars[st].setY(1);
            }
            _stars[st].setY(_stars[st].getY() + 1);
            mvwaddch(win, _stars[st].getY(), _stars[st].getX(), '.');                       
            //_stars[st].moveStar(win, 1);
        }
        _enemies.moveEnemies(win, max_x, max_y);
        //_enemy.moveEnemy(win, max_x, max_y, 1);
        //_enemy2.moveEnemy(win, max_x, max_y, 1);
        // p = -1;
        // while (++p < 5) {
        //     Enemies[p].moveEnemy(win, max_x, max_y, 1);
        // }
        keyPressed = wgetch(win);
        checkCollision(win,_player);
        //mvwprintw(win, 5, 1, std::to_string(_player.isAlive()).c_str());
        //mvwprintw(win, 6, 1, std::to_string(_player.getHP()).c_str());
        mvwprintw(win, 20, 1, std::to_string(max_x).c_str());
        if (_player.isAlive()) {
            switch(keyPressed) {
                case 'z':
                    break;
                case KEY_UP:
                    moveUp(win, _player);
                    break;
                case KEY_DOWN:
                    moveDown(win, _player, max_y);
                    break;
                case KEY_LEFT:
                    moveLeft(win, _player);
                    break;
                case KEY_RIGHT:
                    moveRight(win, _player, max_x);
                    break;
                default:
                    break;
            }   
        }
        Frame++;
        mvwprintw(score, 4, 2, "Frames Rendered: ");
        mvwprintw(score, 4, 19, std::to_string(Frame).c_str());
        usleep(150000);
        box(win, '+', '+');
        wrefresh(win);
        wrefresh(score);
    }
}