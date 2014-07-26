#include "maze.cMaze.h"

using namespace std;

int main() {
    cMaze maze;
    char choice = 0;
    bool generated = false;

    seedRNG();

    while (choice != 'x') {
        if (generated) maze.render();

        cout << "Maze generation algorithms:" << endl
             << "  1. Binary" << endl
             << "  2. Subdivision" << endl
             << "  3. DFS" << endl
             << "  4. Prim" << endl
             << "  5. Kruskal" << endl;

        if (generated) {
            do {
                cout << "Please enter 1-5 to regenerate with a different algorithm, "
                     << "\"s\" to solve, \"v\" to solve visually, or \"x\" to quit: " << endl;
                cin >> choice;
            } while (choice != 'x' && choice != 's' && choice != 'v' && (choice < '1' || choice > '5'));
        } else {
            do {
                cout << "Please select an algorithm (1-5), or \"x\" to quit: " << endl;
                cin >> choice;
            } while (choice != 'x' && (choice < '1' || choice > '5'));
        }

        switch (choice) {
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
              int width, height;
              do {
                  cout << "Enter width (3-19): " << endl;
                  cin >> width;
              } while (width < 3 || width > 19);

              do {
                  cout << "Enter height (3-19): " << endl;
                  cin >> height;
              } while (height < 3 || height > 19);

              maze.create(width, height);
              maze.generate((ALGORITHMS_ENUM)(choice - '1'));
              generated = true;
              break;
            case 's':
              maze.solve(1, 1, maze.getWidth() - 1, maze.getHeight() - 1, false);
              break;
            case 'v':
              maze.solve(1, 1, maze.getWidth() - 1, maze.getHeight() - 1, true);
              break;
            case 'x':
              break;
        }
    }

	  return 0;
}
