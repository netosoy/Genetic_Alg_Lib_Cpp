#include &lt;cstdlib&gt;
#include &lt;iostream&gt;
#include &lt;string&gt;

using namespace std;

const string RIGHT("right");
const string LEFT("left");
const string UP("up");
const string DOWN("down");
const string AHEAD("ahead");

const string labyrinth[8][8] = {{"RD",    "LR",    "LRD",    "LRD",    "LRD",    "LR",    "LD",    "D"},
 {"UD",    "R",    "LUD",    "U",    "UD",    "D",    "RUD",    "LU"},
 {"UD",    "D",    "U",    "D",    "UD",    "UD",    "U",    "D"},
 {"UD",    "UD",    "RD",    "LU",    "U",    "RUD",    "LRD",    "LUD"},
 {"UD",    "UD",    "LU",    "LRD",    "LRD",    "LU",    "UD",    "U"},
 {"UD",    "RU",    "LR",    "LUD",    "UD",    "D",    "RU",    "LD"},
 {"UD",    "RD",    "LR",    "LU",    "U",    "RUD",    "LD",    "UD"},
 {"RU",    "LRU",    "LR",    "LRU",    "LR",    "LU",    "U",    "U"}};

void Move(const string &amp;direction, string &amp;head, int &amp;x, int &amp;y);
void TurnAround(string &amp;head);
bool CanIgo(const string &amp;direction, string &amp;head, int &amp;x, int &amp;y);

int main(int argc, char *argv[])
{
string head = DOWN;

int xPosition = 0;
int yPosition = 0;
int xEndPosition = 7;
int yEndPosition = 7;

while(((xPosition != xEndPosition) || (yPosition != yEndPosition)))
{
 if (CanIgo(RIGHT, head, xPosition, yPosition) == true)
 {
 cout&lt;&lt;"RIGHT"&lt;&lt;endl;
 cout&lt;&lt;"HEAD: "&lt;&lt;head&lt;&lt;endl;
 Move(RIGHT, head, xPosition, yPosition );
 cout&lt;&lt;"XY POSITION: "&lt;&lt;xPosition&lt;&lt;", "&lt;&lt;yPosition&lt;&lt;endl;
 cout&lt;&lt;"HEAD: "&lt;&lt;head&lt;&lt;endl&lt;&lt;endl;
 }
 else if (CanIgo(AHEAD, head, xPosition, yPosition) == true)
 {
 cout&lt;&lt;"AHEAD"&lt;&lt;endl;
 cout&lt;&lt;"HEAD: "&lt;&lt;head&lt;&lt;endl;
 Move(AHEAD, head, xPosition, yPosition);
 cout&lt;&lt;"XY POSITION: "&lt;&lt;xPosition&lt;&lt;", "&lt;&lt;yPosition&lt;&lt;endl;
 cout&lt;&lt;"HEAD: "&lt;&lt;head&lt;&lt;endl&lt;&lt;endl;
 }
 else if (CanIgo(LEFT, head, xPosition, yPosition) == true)
 {
 cout&lt;&lt;"LEFT"&lt;&lt;endl;
 cout&lt;&lt;"HEAD: "&lt;&lt;head&lt;&lt;endl;
 Move(LEFT, head, xPosition, yPosition);
 cout&lt;&lt;"XY POSITION: "&lt;&lt;xPosition&lt;&lt;", "&lt;&lt;yPosition&lt;&lt;endl;
 cout&lt;&lt;"HEAD: "&lt;&lt;head&lt;&lt;endl&lt;&lt;endl;
 }
 else
 {
 TurnAround(head);
 }
}

cout&lt;&lt;"X POSITION: "&lt;&lt;xPosition&lt;&lt;", Y POSITION: "&lt;&lt;yPosition&lt;&lt;endl&lt;&lt;endl;

 return EXIT_SUCCESS;
}

void Move(const string &amp;direction, string &amp;head, int &amp;x, int &amp;y)
{
 if(head == DOWN)
 {
 if(direction == AHEAD) { head = DOWN;y++;}
 if(direction == RIGHT) { head = LEFT; x--;}
 if(direction == LEFT) { head = RIGHT; x++;}
 }
 else if(head == UP)
 {
 if(direction == AHEAD) y--;
 if(direction == RIGHT) { head = RIGHT; x++;}
 if(direction == LEFT) { head = LEFT; x--;}
 }
 else if(head == RIGHT)
 {
 if(direction == AHEAD) x++;
 if(direction == RIGHT) { head = DOWN; y++;}
 if(direction == LEFT) { head = UP; y--;}
 }
 else if(head == LEFT)
 {
 if(direction == AHEAD) x--;
 if(direction == RIGHT) { head = UP; y--;}
 if(direction == LEFT) { head = DOWN; y++;}
 }
 return;
 }

void TurnAround(string &amp;head)
{
 if (head == UP) {head = DOWN; return;}
 if (head == DOWN) {head = UP; return;}
 if (head == RIGHT) {head = LEFT; return;}
 if (head == LEFT) {head = RIGHT; return;}
 }

bool CanIgo(const string &amp;direction, string &amp;head, int &amp;x, int &amp;y)
{
 string str1 (labyrinth[y][x]);
 string str2;

 if(head == DOWN)
 {
     if(direction == AHEAD) str2 = 'D';
     else if(direction == RIGHT) str2 = 'L';
     else if(direction == LEFT) str2 = 'R';
 }
 else if(head == UP)
 {
     if(direction == AHEAD) str2 = 'U';
     else if(direction == RIGHT) str2 = 'R';
     else if(direction == LEFT) str2 = 'L';
 }
 else if(head == RIGHT)
 {
     if(direction == AHEAD) str2 = 'R';
     else if(direction == RIGHT) str2 = 'D';
     else if(direction == LEFT) str2 = 'U';
 }
 else if(head == LEFT)
 {
     if(direction == AHEAD) str2 = 'L';
     else if(direction == RIGHT) str2 = 'U';
     else if(direction == LEFT) str2 = 'D';
 }

 string::size_type loc = str1.find( str2, 0 );
 if( loc != string::npos )
 {
 return true;
 }
 else
 {
 return false;
 }
 }
