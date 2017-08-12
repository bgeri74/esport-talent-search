/**
 * @brief Benchmarking Cognitive Abilities of the Brain with Computer Games
 *
 * @file BrainBThread.cpp
 * @author  Norbert Bátfai <nbatfai@gmail.com>
 * @version 0.0.1
 *
 * @section LICENSE
 *
 * Copyright (C) 2017 Norbert Bátfai, nbatfai@gmail.com
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * @section DESCRIPTION
 *
 */

#include "BrainBThread.h"

BrainBThread::BrainBThread(int w, int h)
{
    this->w = w;
    this->h = h;

    std::srand(std::time(0));

    Hero me(w / 2 + 200.0 * std::rand() / (RAND_MAX + 1.0) - 100,
            h / 2 + 200.0 * std::rand() / (RAND_MAX + 1.0) - 100, 255.0 * std::rand() / (RAND_MAX + 1.0), 9);
    Hero other1(w / 2 + 200.0 * std::rand() / (RAND_MAX + 1.0) - 100,
                h / 2 + 200.0 * std::rand() / (RAND_MAX + 1.0) - 100, 255.0 * std::rand() / (RAND_MAX + 1.0), 5, "Norbi Entropy");
    Hero other2(w / 2 + 200.0 * std::rand() / (RAND_MAX + 1.0) - 100,
                h / 2 + 200.0 * std::rand() / (RAND_MAX + 1.0) - 100, 255.0 * std::rand() / (RAND_MAX + 1.0), 3, "Greta Entropy");
    Hero other4(w / 2 + 200.0 * std::rand() / (RAND_MAX + 1.0) - 100,
                h / 2 + 200.0 * std::rand() / (RAND_MAX + 1.0) - 100, 255.0 * std::rand() / (RAND_MAX + 1.0), 5, "Nandi Entropy");
    Hero other5(w / 2 + 200.0 * std::rand() / (RAND_MAX + 1.0) - 100,
                h / 2 + 200.0 * std::rand() / (RAND_MAX + 1.0) - 100, 255.0 * std::rand() / (RAND_MAX + 1.0), 7, "Matyi Entropy");

    heroes.push_back(me);
    heroes.push_back(other1);
    heroes.push_back(other2);
    heroes.push_back(other4);
    heroes.push_back(other5);

}

BrainBThread::~BrainBThread()
{

}

void BrainBThread::run()
{
    while (true) {

        QThread::msleep(delay);

        if (!paused) {

            ++time;

            devel();
            draw();

            if (time % 300 == 0) {

                emit stats(time);

            }

        }

    }

}

void BrainBThread::pause()
{

    paused = !paused;

}
