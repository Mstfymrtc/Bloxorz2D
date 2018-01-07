#include <stdio.h>
#include <stdlib.h>
#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <time.h>
#include <math.h>
#include<allegro5/allegro_audio.h>
#include<allegro5/allegro_acodec.h>

#define f(x,y) map.Nodes[x][y]=Filled
#define w(x,y) map.Nodes [x][y]=Win
#define or(x,y) map.Nodes[x][y]=OrGate
#define and(x,y) map.Nodes[x][y]=AndGate


void DrawMap();
int level = 0;
int win = 0;
int count = 0;
typedef struct {
	int x;
	int y;
}POSITION;

typedef enum {
	Empty, Filled, Player, Win, OrGate, AndGate
}NODE;

typedef struct {
	int WidthCount;
	int HeightCount;
	NODE ** Nodes;
	POSITION Player[2];
}MAP;

MAP map;
ALLEGRO_FONT *fontsmall;
ALLEGRO_DISPLAY * display;
float UnitSize;
ALLEGRO_COLOR PlayerColor;

void CreateMap(int width, int height) { // kaça kaçlýk tablo yapýlacak o belirleniyor
	map.WidthCount = width;
	map.HeightCount = height;
	map.Nodes = (NODE **)malloc(sizeof(NODE *)*width);
	for (int x = 0; x < width; x++) {
		map.Nodes[x] = (NODE *)malloc(sizeof(NODE)*height);
		for (int y = 0; y < height; y++) {
			map.Nodes[x][y] = Empty;
		}


	}


}

void FirstLevel() {

	f(6, 7);
	f(7, 7);
	f(8, 7);
	f(4, 8);
	f(5, 8);
	f(6, 8);
	f(7, 8);
	f(8, 8);
	f(9, 8);
	f(10, 8);
	f(11, 8);
	f(6, 9);
	f(7, 9);
	f(8, 9);
	f(9, 9);
	f(10, 9);
	f(11, 9);
	f(12, 9);
	f(13, 9);
	f(14, 9);
	f(7, 10);
	f(8, 10);
	f(9, 10);
	f(10, 10);
	f(11, 10);
	f(12, 10);
	f(13, 10);
	f(14, 10);
	f(15, 10);
	f(11, 11);
	f(12, 11);
	w(13, 11);///////// specifies target
	f(14, 11);
	f(15, 11);
	f(12, 12);
	f(13, 12);
	f(14, 12);
}
void SecondLevel() {
	f(5, 9);
	f(6, 9);
	f(7, 9);
	f(8, 9);
	f(9, 9);
	f(10, 9);
	f(11, 9);
	f(12, 9);
	f(5, 10);
	f(6, 10);
	f(7, 10);
	f(8, 10);
	f(9, 10);
	f(10, 10);
	f(11, 10);
	f(12, 10);
	f(7, 11);
	f(8, 11);
	f(7, 12);
	f(8, 12);
	f(10, 7);
	f(10, 8);
	f(11, 7);
	f(11, 8);
	f(12, 7);
	f(12, 8);
	f(13, 7);
	f(13, 8);
	f(14, 7);
	f(14, 8);
	w(14, 9);
}
void ThirdLevel() {

	f(2, 8);
	f(2, 9);
	f(2, 10);
	f(2, 11);
	f(2, 12);
	f(3, 8);
	f(3, 9);
	f(3, 10);
	f(3, 11);
	f(3, 12);
	f(4, 8);
	or (4, 9); //OR GATE
	f(4, 10);
	f(4, 11);
	f(4, 12);
	f(5, 8);
	f(5, 9);
	f(5, 10);
	f(5, 11);
	f(5, 12);
	//f(6,12); //bridge
	//f(7,12); //bridge
	f(8, 7);
	f(8, 8);
	f(8, 9);
	f(8, 10);
	f(8, 11);
	f(8, 12);
	f(9, 7);
	f(9, 8);
	f(9, 9);
	f(9, 10);
	f(9, 11);
	f(9, 12);
	f(10, 7);
	and (10, 8); //AND GATE
	f(10, 9);
	f(10, 10);
	f(10, 11);
	f(10, 12);
	f(11, 7);
	f(11, 8);
	f(11, 9);
	f(11, 10);
	f(11, 11);
	f(11, 12);
	//f(12, 11); // bridge
	//f(13, 11);// bridge
	f(14, 7);
	f(14, 8);
	f(14, 9);
	f(14, 10);
	f(14, 11);
	f(15, 7);
	w(15, 8);
	f(15, 9);
	f(15, 10);
	f(15, 11);
	f(16, 7);
	f(16, 8);
	f(16, 9);
	f(16, 10);
	f(16, 11);







}


void Start() {



	level = 1;
	count = 0;
	UnitSize = 30;

	int HorizontalSquares = UnitSize - 10, VerticalSquares = UnitSize - 10;
	PlayerColor = al_map_rgb(255, 0, 0); // specifies player color

	fontsmall = al_load_ttf_font("ostrich-regular.ttf", 30, NULL);

	al_clear_to_color(al_map_rgb(51, 0, 51)); // Arkaplan rengini deðiþtirir

	CreateMap(HorizontalSquares, VerticalSquares); // Creating map

												   //Fill(2, 2, HorizontalSquares - 2, VerticalSquares - 2, Filled); // Filling nodes

												   /////////////////////////////////////////////////////CREATING 1ST MAP////////////////////////////////////


	FirstLevel();
	//starting coordinates

	map.Player[0].x = 7;
	map.Player[0].y = 8;
	map.Player[1].x = 7;
	map.Player[1].y = 8;

	DrawMap();

}
void Start2() {
	level = 2;
	UnitSize = 30;
	count = 0;

	int HorizontalSquares = UnitSize - 10, VerticalSquares = UnitSize - 10;
	al_init();
	PlayerColor = al_map_rgb(255, 0, 0); // specifies player color

	display = al_create_display(600, 600);
	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_install_keyboard();
	al_install_audio();
	al_init_acodec_addon();

	al_clear_to_color(al_map_rgb(51, 0, 51)); // Arkaplan rengini deðiþtirir

	CreateMap(HorizontalSquares, VerticalSquares); // Creating map


												   /////////////////////////////////////////////////////CREATING 2ST MAP////////////////////////////////////


	SecondLevel();
	//starting coordinates

	map.Player[0].x = 5;
	map.Player[0].y = 10;
	map.Player[1].x = 5;
	map.Player[1].y = 10;

	DrawMap();

}
void Start3() {
	level = 3;
	UnitSize = 30;
	count = 0;

	int HorizontalSquares = UnitSize - 10, VerticalSquares = UnitSize - 10;
	al_init();
	PlayerColor = al_map_rgb(255, 0, 0); // specifies player color

	display = al_create_display(600, 600);
	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_install_keyboard();
	al_install_audio();
	al_init_acodec_addon();


	al_clear_to_color(al_map_rgb(51, 0, 51)); // Arkaplan rengini deðiþtirir

	CreateMap(HorizontalSquares, VerticalSquares); // Creating map


												   /////////////////////////////////////////////////////CREATING 3RD MAP////////////////////////////////////


	ThirdLevel();	//starting coordinates

	map.Player[0].x = 3;
	map.Player[0].y = 11;
	map.Player[1].x = 3;
	map.Player[1].y = 11;

	DrawMap();


}
ALLEGRO_COLOR Color(NODE n) {
	switch (n)
	{
	case Empty: return al_map_rgb(51, 0, 51); // boþ yerlerin rengi
	case Filled: return al_map_rgb(255, 255, 255); // dolu yerlerin rengi	
	case Win: return al_map_rgb(0, 94, 255);
	case OrGate: return al_map_rgb(75, 60, 60);
	case AndGate: return al_map_rgb(0, 0, 0);
	default:
		return al_map_rgb(0, 0, 0);
	}
}
void DrawMap() {
	float margin = 0.018;

	for (int x = 0; x < map.WidthCount; x++) {
		for (int y = 0; y < map.HeightCount; y++) {
			al_draw_filled_rectangle(UnitSize*x + UnitSize * margin, UnitSize*y + UnitSize * margin, UnitSize*(x + 1) - UnitSize * margin, UnitSize*(y + 1) - UnitSize * margin, Color(map.Nodes[x][y]));
		}
	}

	al_draw_filled_rectangle(UnitSize*map.Player[0].x + UnitSize * margin, UnitSize*map.Player[0].y + UnitSize * margin, UnitSize*(map.Player[0].x + 1) - UnitSize * margin, UnitSize*(map.Player[0].y + 1) - UnitSize * margin, PlayerColor);
	al_draw_filled_rectangle(UnitSize*map.Player[1].x + UnitSize * margin, UnitSize*map.Player[1].y + UnitSize * margin, UnitSize*(map.Player[1].x + 1) - UnitSize * margin, UnitSize*(map.Player[1].y + 1) - UnitSize * margin, PlayerColor);

	al_draw_textf(fontsmall, al_map_rgb(255, 255, 255), 50, 50, NULL, "Moves: %d", count);
	al_flip_display();
	al_clear_to_color(al_map_rgb(51, 0, 51));


}


int main() {

	al_init();
	display = al_create_display(600, 600);
	al_clear_to_color(al_map_rgb(51, 0, 51));

	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_install_keyboard();
	al_install_audio();
	al_init_acodec_addon();


	ALLEGRO_FONT *fontstart;
	ALLEGRO_FONT *fontstartsmall;
	ALLEGRO_FONT *fontnames;
	fontstart = al_load_ttf_font("ostrich-regular.ttf", 120, NULL);
	fontstartsmall = al_load_ttf_font("ostrich-regular.ttf", 50, NULL);
	fontnames = al_load_ttf_font("ostrich-regular.ttf", 20, NULL);
	al_draw_text(fontstart, al_map_rgb(255, 255, 255), 140, 200, NULL, "BLOXORZ");
	al_draw_text(fontstartsmall, al_map_rgb(255, 255, 255), 435, 252, NULL, "2D");
	al_draw_text(fontnames, al_map_rgb(255, 255, 255), 118, 500, NULL, "Dila ASLAN | Mustafa YUMURTACI | Ceyhan TURNALI | Kaan CELIKER");

	al_flip_display();

	al_rest(3);


	Start();


	//Start3();


	ALLEGRO_FONT *fontmain = al_load_ttf_font("pacifico.ttf", 100, NULL);
	ALLEGRO_FONT *fontsecond = al_load_ttf_font("ostrich-regular.ttf", 50, NULL);

	ALLEGRO_SAMPLE *move = NULL;
	ALLEGRO_SAMPLE *lose = NULL;
	ALLEGRO_SAMPLE *winning = NULL;
	//ALLEGRO_SAMPLE *background = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	al_reserve_samples(20);
	lose = al_load_sample("lose.wav");
	move = al_load_sample("move.wav");
	winning = al_load_sample("winning.wav");
	//background = al_load_sample("background.wav");
	//al_play_sample(background, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);

	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_display_event_source(display));

	while (1)
	{

		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{




			switch (ev.keyboard.keycode)
			{

			case ALLEGRO_KEY_UP:
				al_play_sample(move, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
				count++;

				//yana yatýk
				if (fabs(map.Player[1].x - map.Player[0].x) == 1)
				{
					map.Player[1].y -= 1;
					map.Player[0].y -= 1;

				}
				//dikey þekilde(2 kare)

				else if (map.Player[0].y - map.Player[1].y == 1)
				{
					map.Player[0].y -= 2;
					map.Player[1].y -= 1;
				}
				else if (map.Player[1].y - map.Player[0].y == 1)
				{
					map.Player[0].y -= 1;
					map.Player[1].y -= 2;
				}
				// tek kare
				else if (map.Player[0].x == map.Player[1].x && map.Player[0].y == map.Player[1].y)
				{
					map.Player[1].y -= 1;
					map.Player[0].y -= 2;
				}


				break;
			case ALLEGRO_KEY_DOWN:
				al_play_sample(move, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
				count++;

				// yatay þekidle

				if (fabs(map.Player[1].x - map.Player[0].x) == 1)
				{
					map.Player[1].y += 1;
					map.Player[0].y += 1;

				}
				////////// dikey þekilde

				else if (map.Player[0].y - map.Player[1].y == 1)
				{
					map.Player[0].y += 1;
					map.Player[1].y += 2;
				}
				else if (map.Player[1].y - map.Player[0].y == 1)
				{
					map.Player[0].y += 2;
					map.Player[1].y += 1;
				}
				//tek kare

				else if (map.Player[0].x == map.Player[1].x && map.Player[0].y == map.Player[1].y)
				{
					map.Player[0].y += 1;
					map.Player[1].y += 2;
				}

				break;

			case ALLEGRO_KEY_LEFT:
				al_play_sample(move, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
				count++;


				if (map.Player[1].x - map.Player[0].x == 1)
				{
					map.Player[0].x -= 1;
					map.Player[1].x -= 2;


				}
				else if (map.Player[0].x - map.Player[1].x == 1)
				{
					map.Player[0].x -= 2;
					map.Player[1].x -= 1;


				}

				// dikey þekilde   


				else if (fabs(map.Player[0].y - map.Player[1].y) == 1)
				{
					map.Player[0].x -= 1;
					map.Player[1].x -= 1;
				}

				//tek kare


				else if (map.Player[0].x == map.Player[1].x && map.Player[0].y == map.Player[1].y)
				{
					map.Player[1].x -= 2;
					map.Player[0].x -= 1;
				}
				break;

			case ALLEGRO_KEY_RIGHT:
				al_play_sample(move, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
				count++;

				// yatay þekilde

				if (map.Player[1].x - map.Player[0].x == 1)
				{
					map.Player[0].x += 2;
					map.Player[1].x += 1;


				}
				else if (map.Player[0].x - map.Player[1].x == 1)
				{
					map.Player[0].x += 1;
					map.Player[1].x += 2;

				}

				//dikey þekilde
				else if (fabs(map.Player[0].y - map.Player[1].y) == 1)
				{
					map.Player[0].x += 1;
					map.Player[1].x += 1;
				}

				//tek kare
				else if (map.Player[0].x == map.Player[1].x && map.Player[0].y == map.Player[1].y)
				{
					map.Player[1].x += 2;
					map.Player[0].x += 1;
				}

				break;

			}

			if (map.Nodes[map.Player[0].x][map.Player[0].y] == OrGate || map.Nodes[map.Player[1].x][map.Player[1].y] == OrGate)
			{
				f(6, 12);
				f(7, 12);

			}
			else if (map.Nodes[map.Player[0].x][map.Player[0].y] == AndGate && map.Nodes[map.Player[1].x][map.Player[1].y] == AndGate)
			{
				f(12, 11); // bridge
				f(13, 11);
			}

			DrawMap();

			if (map.Nodes[map.Player[0].x][map.Player[0].y] == Empty || map.Nodes[map.Player[1].x][map.Player[1].y] == Empty)
			{
				al_draw_text(fontmain, al_map_rgb(255, 255, 255), 70, 170, NULL, "Game Over");
				al_draw_textf(fontsecond, al_map_rgb(255, 255, 255), 200, 350, NULL, "with %d moves!", count);
				al_play_sample(lose, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);

				al_flip_display();
				al_rest(2.5);

				if (level == 1)
				{
					Start();
				}
				else if (level == 2)
				{
					Start2();
				}
				else if (level == 3)
				{
					Start3();

				}

			}

			if (map.Nodes[map.Player[0].x][map.Player[0].y] == Win && map.Nodes[map.Player[1].x][map.Player[1].y] == Win)
			{
				win++;
				al_draw_text(fontmain, al_map_rgb(255, 255, 255), 100, 170, NULL, "You Win");
				al_draw_textf(fontsecond, al_map_rgb(255, 255, 255), 190, 350, NULL, "with %d moves!", count);

				al_play_sample(winning, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);

				al_flip_display();
				al_rest(2);
				al_destroy_display(display);


				//////////////////// LEVEL PROCESS
				if (win == 1)
					Start2();

				else if (win == 2) {
					Start3();

				}
				else if (win == 3)
				{
					break;
				}



			}
		}





	}

}