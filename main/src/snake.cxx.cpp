#include<SDL2/SDL.h>
//w=1440 h=2614
#include<stdlib.h>
#include<time.h>
#include<SDL2/SDL_image.h>
#include<vector>
#include<SDL2/SDL_mixer.h>
#include<SDL2/SDL_ttf.h>
SDL_Window* window;
SDL_Renderer* render;
int branch=1;
int leaf_size;
int ref;
int HighScore;
int sizze;
int main(int argc, char *argv[])
{
	srand (time(0));
	int back=0;
	int left=0, right=0,up=0,down=0;
	int startx,starty,endx,endy;
	int drag=0;
	int score=0;
	int dead=0;
	int delay=100;
	int u,v;
	int tlp_angle=0;
	int jump=0;
int tlp_display=0;
int box_in_width=0;
	int skip=0;
	int num=0;
	int start_check=0;
	int speed=1;
	char text[44];
	sprintf(text,"%d",score);
int increase=1, decrease=0;
	std::vector<int>tail;
tail.push_back(0);
	int count=0;
	//screen size
int ran=1;
int halt=0;
int halt2=0;
int check_speed=0;
int has_left=1;
int box_in_height=0;
int fresh=0;
int point=15;
int on_pause=0;
int speed_limit=100;
int fall=0;
char temp[55];
int touch_escape=0;
	Uint32 last,now;
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG);
	Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2028);
	window=SDL_CreateWindow("snake",100,100,100,100,0);
	//load x button for catalog
		render=SDL_CreateRenderer(window,-1,0);
		TTF_Init();
		int w,h;
		int selected_snake=1;
SDL_GL_GetDrawableSize(window,&w,&h);
int size=w/14;
	TTF_Font* font = TTF_OpenFont("Jersey25-Regular.ttf", 100);
	SDL_Color color={0,0,0};
	SDL_Surface* surface=TTF_RenderText_Solid(font,"X",color);
	SDL_Texture* texture=SDL_CreateTextureFromSurface(render,surface);
	SDL_Color high_color{200,105,25};
	SDL_Surface* high=TTF_RenderText_Solid(font,temp,high_color);
	SDL_Texture* high_texture;
SDL_Rect score_rect{0,0,int(0.2*w),int(0.12*h)};
SDL_Texture* score_text=IMG_LoadTexture(render,"score.png");SDL_Color color2={150,100,200};
SDL_Rect score_rect2{int(0.23*w),int(0.06*w),size,size};
SDL_Surface* surface2=TTF_RenderText_Solid(font,text,color2);
	//
	SDL_Texture* value=SDL_CreateTextureFromSurface(render,surface2);

	SDL_Rect snake{size*2,size*5,size,size};
	SDL_Rect frt{int(0.6*w),int(0.7*h),25,25};
	SDL_Rect hitbox=frt;
	hitbox.w=hitbox.h=10;
		
int is_tlp=0;
int tlp_count=(h/size)*2+20;
	SDL_Texture* fruitred=IMG_LoadTexture(render,"apple_red.png");
	SDL_Texture* fruitgreen=IMG_LoadTexture(render,"apple_green.png");
	SDL_Texture* black_hole=IMG_LoadTexture(render,"blackhole.png");
	SDL_Texture* head1=IMG_LoadTexture(render,"snake_green_head.png");
	SDL_Texture* head2=IMG_LoadTexture(render,"snake_yellow_head.png");
	SDL_Texture* body1=IMG_LoadTexture(render,"snake_green_blob.png");
	SDL_Texture* body2=IMG_LoadTexture(render,"snake_yellow_blob.png");
	SDL_Texture* wall=IMG_LoadTexture(render,"block_planks.png");SDL_Rect wall_rect{0,int(0.12*h),size,size};
	SDL_Texture* cactus=IMG_LoadTexture(render,"cactus.png");
	SDL_Rect cactus_rect{0,int(0.12*h),size,size};
	SDL_Texture* bush=IMG_LoadTexture(render,"bush.png");
	SDL_Rect bush_rect{0,int(0.1*w),size,size};
	SDL_Texture* logo=IMG_LoadTexture(render,"logo.png");
	SDL_Texture* leaf=IMG_LoadTexture(render,"leaf.png");
SDL_Rect menu{int(0.2*w),int(0.3*h),int(0.6*w),int(0.4*h)};
	SDL_Rect logo_rect{int(0.2*w),int(0.01*h),int(0.5*w),int(0.2*h)};
	SDL_Texture* play_button=IMG_LoadTexture(render,"play_button.png");
	SDL_Rect play_rect{int(0.3*w),int(0.35*h),int(0.5*menu.w),int(0.15*menu.h)};
	SDL_Rect catalog_rect=play_rect;
	catalog_rect.y=int(0.45*h);
	SDL_Texture* catalog_button=IMG_LoadTexture(render,"catalog_button.png");
	SDL_Rect blur{0,0,w,h};
	SDL_Rect pause_rect{w-size*2,10,int(0.1*w),int(0.05*h)};
	SDL_Texture* pause=IMG_LoadTexture(render,"pause_button.png");
	//Music
Mix_Music* background_music=Mix_LoadMUS("background_music.mp3");
SDL_Rect select_rect{int(0.28*w),int(0.52*h),int(0.4*w),int(0.14*w)};
SDL_Texture* select=IMG_LoadTexture(render,"select.png");
SDL_Rect arrow_rect{int(0.25*w),int(0.62*h),100,100};
SDL_Texture* arrow=IMG_LoadTexture(render,"arrow3.png");
SDL_Rect chosen=arrow_rect;
chosen.x+=250;
SDL_Rect app_rect{int(0.1*w),int(0.3*h),int(0.8*w),int(0.4*h)};
SDL_Texture* app_pic=IMG_LoadTexture(render,"app_pic.png");
SDL_Rect escape{(app_rect.w+app_rect.x)-100,app_rect.y,int(0.07*w),100};
SDL_Rect escape_rect{int((escape.x+escape.w)-70),escape.y,surface->w,surface->h};
SDL_Event  e;
SDL_Rect resume_rect=play_rect;
SDL_Texture* resume=IMG_LoadTexture(render,"resume_button.png");
SDL_Texture* main_menu=IMG_LoadTexture(render,"main_menu.png");
SDL_Texture* dead_head[3];
dead_head[1]=IMG_LoadTexture(render,"snake_green_xx.png");
dead_head[2]=IMG_LoadTexture(render,"snake_yellow_xx.png");
Mix_Chunk* bite=Mix_LoadWAV("bite.mp3");
SDL_Texture* restart=IMG_LoadTexture(render,"restart.png");
ref=w/size;
sizze=size;
int index=0;
SDL_Rect big[w*5];
struct hole{
	int x=sizze*(rand()%10+2);
	int y=sizze*(rand()%19+5);
	int p,q;
}hole[w];
SDL_Rect pit[w];
pit[index].x=hole[index].x;
pit[index].y=hole[index].y;
pit[index].w=pit[index].h=size/2;
leaf_size=w*h;
big[index].x=pit[index].x-70;
big[index].y=pit[index].y-70;
big[index].w=big[index].h=size*2;
struct Leaf{
	SDL_Rect leaf_rect[2900];
float angle=0.2;
}Leaf;
for(int i=0;i<=h/2;i++){
Leaf.leaf_rect[i].w=Leaf.leaf_rect[i].h=50;
Leaf.leaf_rect[i].x=(rand()%w)*100;
Leaf.leaf_rect[i].y=-(rand()%h);

}
//speed
SDL_Rect speed_rect{500,500,size,size};
SDL_Texture* speed_ball=IMG_LoadTexture(render,"speed_ball.png");
int speed_point=15;
int eaten=0;
//
///Teleportation jutsu
	int phase[2];
	int tlp_point=9;
SDL_Rect tlp_rect[4];
tlp_rect[0]={int(0.3*w),int(0.16*h),size, size};
tlp_rect[1]={int(0.85*w),int(0.5*h),size,size};
tlp_rect[2]={int(0.5*w),int(0.93*h), size,size};
tlp_rect[3]={int (0.07*w),int(0.5*h),size, size};
SDL_Texture* tlp=IMG_LoadTexture(render
,"teleport.png");
Mix_PlayMusic(background_music,-1);
SDL_SetRenderDrawBlendMode(render,SDL_BLENDMODE_BLEND);
SDL_Surface* music_surface=TTF_RenderText_Solid(font,"Music :",color);
SDL_Texture* music_texture=SDL_CreateTextureFromSurface(render, music_surface);
SDL_Texture* click[2];
click[0]=IMG_LoadTexture(render,"on.png");
click [1]=IMG_LoadTexture(render,"off.png");
SDL_Rect click_rect{select_rect.x+select_rect.w,select_rect.y+50,100,100};

int click_state=0;
SDL_Surface* closing_surface=TTF_RenderText_Solid(font,"Game Over",color);
SDL_Texture* closing_text=SDL_CreateTextureFromSurface(render, closing_surface);
SDL_Rect closing_rect=play_rect;
closing_rect.y-=50;
SDL_Rect dead_rect{closing_rect.x+closing_rect.w+50, closing_rect.y+30,size,size};
while(1){
	//BRANCH 1
if(branch==1){
while(1){
		SDL_SetRenderDrawColor(render,100,200,00,100);
		SDL_RenderClear(render);
		for(int i=0;i<=h/2;i++){
			Leaf.leaf_rect[0].y=100;
			SDL_RenderCopyEx(render,leaf,0,&Leaf.leaf_rect[i],Leaf.angle,0,SDL_FLIP_NONE);
			Leaf.leaf_rect[i].y++;
				if(Leaf.leaf_rect[i].y==h)Leaf.leaf_rect[i].y=-10;
			
		}
Leaf.angle+=0.2;
SDL_SetRenderDrawColor(render,220,105,0,225);
SDL_RenderCopy(render,logo,0,&logo_rect);
SDL_RenderFillRect(render,&menu);
SDL_RenderCopy(render,play_button,0,&play_rect);
SDL_RenderCopy(render, catalog_button,0,&catalog_rect);
SDL_RenderCopy(render,select,0,&select_rect);
SDL_RenderCopyEx(render,arrow,0,&arrow_rect,0,0,SDL_FLIP_HORIZONTAL);
arrow_rect.x+=int(0.42*w);
SDL_RenderCopy(render,arrow,0,&arrow_rect);
arrow_rect.x=int(0.2*w);
//draw selected snake
if(selected_snake==1)SDL_RenderCopy(render,head1,0,&chosen);
if(selected_snake==2)SDL_RenderCopy(render,head2,0,&chosen);
if(touch_escape)halt=0;
if(halt){
	SDL_SetRenderDrawColor(render,225,225,225,150);
	SDL_RenderFillRect(render,&blur);
	SDL_RenderCopy(render,app_pic,0,&app_rect);
	
	SDL_SetRenderDrawColor(render,255,5,5,200);SDL_RenderFillRect(render,&escape);
	SDL_RenderCopy(render, texture,0,&escape_rect);
}
		SDL_RenderPresent(render);
		if(halt){
				while (SDL_PollEvent(&e)){
					int touchx=e.tfinger.x*w;
		int touchy=e.tfinger.y*h;
			if(e.type==SDL_FINGERDOWN){
				if(touchx>=escape.x&&touchx<=escape.x+escape.w&&touchy>=escape.y&&touchy<=escape.y+escape.h) halt=0;
				SDL_Delay(150);
			}
				}
		}
		if(!halt){
		while (SDL_PollEvent(&e)){
			if(e.type==SDL_FINGERDOWN){
		int touchx=e.tfinger.x*w;
		int touchy=e.tfinger.y*h;
if(touchx>=play_rect.x&&touchx<=play_rect.x+play_rect.w&&touchy>=play_rect.y&&touchy<=play_rect.y+play_rect.h)branch=2;
if((touchx>=arrow_rect.x&&touchx<=arrow_rect.x+arrow_rect.w)||(touchx>=arrow_rect.x+600&&touchx<=arrow_rect.x+600+arrow_rect.w)&&touchy>=arrow_rect.y&&touchy<=arrow_rect.y+arrow_rect.h){
	selected_snake=(selected_snake==1)?2:1;
}
		
		if(touchx>=catalog_rect.x&&touchx<=catalog_rect.x+catalog_rect.w&&touchy>=catalog_rect.y&&touchy<=catalog_rect.y+catalog_rect.h)halt=1;
		
		}
		
		}
		}
		else{
		}//
		if(branch==2){
			SDL_Delay(200);
			break;
		}
	
}
SDL_Delay(100);
}//branch 1
else{//BRANCH 2
SDL_SetRenderDrawBlendMode(render,SDL_BLENDMODE_BLEND);
	while (1){
		FILE* file=fopen("recents.txt","r");
		char temp[55];
		while(fgets(temp,sizeof(temp),file)){
		}
		HighScore=atoi(temp);
		sprintf(temp,"HighScore: %d %d %d", HighScore,snake.x,snake.y);
		box_in_height=0;
		box_in_width=0;
		fclose(file);
high=TTF_RenderText_Solid(font,temp,high_color);
		high_texture=SDL_CreateTextureFromSurface(render,high);
			SDL_Rect high_rect{int(0.36*w),int(0.03*h),int(0.48*w),int(0.07*w)};
	
	
		SDL_SetRenderDrawColor(render,100,200,00,100);
		SDL_RenderClear(render);
		SDL_SetRenderDrawColor(render,0,0,00,100);
		//DRAW BOARD
		for(int i=0;i<=w;i+=size){
			SDL_RenderDrawLine(render,i,int(0.25*w),i,h);
		}
		for(int i=int(0.15*h);i<=h;i+=size){
			SDL_RenderDrawLine(render,0,i,w,i);
		}
		SDL_SetRenderDrawColor(render,0,100,225,100);
		//END
		int p=snake.y;
		int q=snake.x;
		for(int i=0;i<=back;i+=2){
		
		snake.y=tail[i];
		snake.x=tail[i+1];	if(i>0&&selected_snake==1&&!skip)SDL_RenderCopy(render,body1,0,&snake);
	if(i>0&&selected_snake==2&&! skip)SDL_RenderCopy(render,body2,0,&snake);
		
		}
		snake.y=p;
		snake.x=q;
		if(selected_snake==1&&!skip&&!fall)SDL_RenderCopy(render,head1,0,&snake);
		if(selected_snake==2&&!skip&&!fall)SDL_RenderCopy(render,head2,0,&snake);
		if(ran)SDL_RenderCopy(render,fruitred,0,&frt);else{
			SDL_RenderCopy(render,fruitgreen,0,&frt);
		}
		
		SDL_RenderFillRect(render,& hitbox);
		//draw wall
		for(int i=0;i<w;i+=size){
		SDL_RenderCopy(render,wall,0,&wall_rect);
		wall_rect.x+=size;
		box_in_width++;
		}
		wall_rect.x=0;
		wall_rect.y=int(0.965*h);
		for(int i=0;i<=w;i+=size){
			SDL_RenderCopy(render,wall,0,&wall_rect);
			wall_rect.x+=size;
		}
		wall_rect.x=0;
		wall_rect.y=int(0.11*h);
		for(int i=200;i<=h;i+=size){
			wall_rect.y+=size;
			SDL_RenderCopy(render,wall,0,&wall_rect);
box_in_height++;

				}
		
		wall_rect.y=int(0.12*h);
		wall_rect.x=(w-size)-5;
		for(int i=100;i<=h;i+=100){
			SDL_RenderCopy(render,wall,0,&wall_rect);
			wall_rect.y+=size;
		}
		wall_rect.x=0;
		wall_rect.y=int(0.12*h);
		//set cactuses
		for(int i=0;i<=w;i+=size*2){
			SDL_RenderCopy(render,cactus,0,&cactus_rect);
			cactus_rect.x+=size*3;
		}
		cactus_rect.x=0;
		cactus_rect.y=h-size;
			for(int i=0;i<=w;i+=size*2){
			SDL_RenderCopy(render,cactus,0,&cactus_rect);
			cactus_rect.x+=size*2;
		}
		cactus_rect.y=int(0.12*h);
		cactus_rect.x=0;
		//set bush
		for(int i=0;i<=h;i+=size*2){
			SDL_RenderCopy(render,bush,0,&bush_rect);
			bush_rect.y+=size*4;
		}
		bush_rect.y=int (0.12*h);
		bush_rect.x=w-size;
		for(int i=0;i<=h;i+=size*3){
		SDL_RenderCopy(render,bush,0,&bush_rect);
			bush_rect.y+=size*4;
		}
		bush_rect.x=0;
		bush_rect.y=int(0.12*h);
		SDL_RenderCopy(render,score_text,0,&score_rect);
		SDL_RenderCopy(render,value,0,&score_rect2);
		SDL_RenderCopy(render,pause,0,&pause_rect);
		if(branch==3){
		SDL_RenderFillRect(render,&menu);
		SDL_RenderCopy(render,resume,0,&play_rect);
		SDL_RenderCopy(render,main_menu,0,&catalog_rect);
		SDL_RenderCopy(render,music_texture,0,&select_rect);
		SDL_RenderCopy(render,click[click_state],0,&click_rect);
		while (SDL_PollEvent(&e)){
			if(e.type==SDL_FINGERDOWN){
			startx=e.tfinger.x*w;
 		starty=e.tfinger.y*h;
 		if(startx>=click_rect.x&&startx<=click_rect.x+click_rect.w&&starty>=click_rect.y&&click_rect.y+click_rect.h){
 			click_state=(click_state==0)?1:0;
 			if(click_state==1)Mix_PauseMusic();
 			else{
 				Mix_ResumeMusic();
 			}
 		}
 		if(startx>=play_rect.x&&startx<=play_rect.x+play_rect.w&&starty>=play_rect.y&&starty<=play_rect.y+play_rect.h){
 			branch=2;
 	
 		
 		}
 			if(startx>=catalog_rect.x&&startx<=catalog_rect.x+catalog_rect.w&&starty>=catalog_rect.y&&starty<=catalog_rect.y+catalog_rect.h&& branch==3){
 				branch=1;
 				tail.clear();
 				delay=100;
 				fresh=1;
 				snake.x=size*2;
 				snake.y=size*5;
 				score=0;
 				speed_limit=100;
 				speed_point=15;
 				speed=1;
 				point=15;
 				fall=0;
 				start_check=0;
 				tlp_display=0;
 				index=0;
 				tlp_point=8;
 				skip=0;
 				phase [0]=phase [1]=10;
 				sprintf(text,"%d",score);
	surface2=TTF_RenderText_Solid(font,text,color2);
	value=SDL_CreateTextureFromSurface(render,surface2);
 				up=0;
 				down=left=right=0;
 				back=0;
 			
 			}
		}
		}
		}
	if(fresh) index=0;
		for(int i=0;i<=index;i++){
				if(SDL_HasIntersection(&snake,&pit[i])&& start_check){
					fall=1;
					delay=16;
				}
				u=pit[i].x;
				v=pit[i].y;
		}
		
		for(int i=0;i<=index;i++){
			
			if(score>7){
				start_check=1;
				SDL_SetRenderDrawColor(render,0,0,0,100);
				SDL_RenderFillRect(render,&pit[i]);
	SDL_RenderCopy(render,black_hole,0,&big[i]);
			}
		
			if(score>point){
				index++;
				int valid=1;
				while(valid){
		hole[index].x=sizze*(rand()%10+2);
 hole[index].y=sizze*(rand()%19+5);
 for(int i=0;i<=back;i+=2){
 			if(hole[index].x==tail[i]&&hole[index].y==tail[i+1])valid=-1;
 }
 if(valid==-1)valid=1;
 else{
 			valid=0;
 }
				}
 pit[index].x=hole[index].x;
pit[index].y=hole[index].y;
pit[index].w=pit[index].h=size/2;
big[index].x=pit[index].x-70;
big[index].y=pit[index].y-70;
big[index].w=big[index].h=size*2;
point+=7;
		}
		}
		
			SDL_RenderCopy(render,high_texture,0,&high_rect);
	if(score>tlp_point){
		tlp_point+=8;
		tlp_display=1;
		
		phase[0]=rand ()%4;
	int valid=1;
	while(valid){
		phase[1]=rand()%4;
		if(phase[1]!=phase[0])valid=0;
	}

	}

		if(tlp_display){
			SDL_RenderCopyEx(render,tlp,0,&tlp_rect[phase[0]],tlp_angle,0,SDL_FLIP_NONE);
				SDL_RenderCopyEx(render,tlp,0,&tlp_rect[phase[1]],tlp_angle,0,SDL_FLIP_NONE);
				tlp_count--;
				tlp_angle+=5;
		}
		if(tlp_count==0){
		tlp_count=(h/size)*2+20;
		tlp_display=0;
		}
	int top=0,bot=0;
	if(jump){
		jump=0;
		has_left=0;
	}
	else{
		has_left=1;
	}
		if(has_left){
		if(SDL_HasIntersection(&snake,&tlp_rect[phase[0]])&&tlp_display){
			snake.x=tlp_rect[phase [1]].x;
			snake.y=tlp_rect[phase[1]].y;
			jump=1;
		}
		else if(SDL_HasIntersection(&snake,&tlp_rect[phase[1]])&&tlp_display){
			snake.x=tlp_rect[phase [0]].x;
			snake.y=tlp_rect[phase[0]].y;
			jump=1;
			}
		}
		if(dead){
			SDL_RenderFillRect(render,&menu);
			SDL_RenderCopy(render, closing_text,0,& closing_rect);
			int temp=closing_rect.x;
		
			SDL_RenderCopy(render,dead_head[selected_snake],0,&dead_rect);
			SDL_RenderCopy(render,restart,0,& catalog_rect);
			int p=select_rect.w;
			int q=select_rect.h;
			select_rect.w=500;
			select_rect.h=150;
			SDL_RenderCopy(render,high_texture,0,& select_rect);
			select_rect.w=p;
	select_rect.h=q;
	while(SDL_PollEvent(&e)){
		if(e.type==SDL_FINGERDOWN){
			int startx=e.tfinger.x*w;
 		int starty=e.tfinger.y*h;
 			if(startx>=catalog_rect.x&&startx<=catalog_rect.x+catalog_rect.w&&starty>=catalog_rect.y&&starty<=catalog_rect.y+catalog_rect.h){
 				branch=2;
 				tail.clear();
 		point=15;
 				tlp_point=8;
 				tlp_display=0;
 				fresh=1;
 				snake.x=size*2;
 				snake.y=size*5;
 				score=0;
 				speed=1;
 				speed_limit=100;
 				speed_point=15;
 				delay=100;
 				fall=0;
 				start_check=0;
 				index=0;
 				skip=0;
 				sprintf(text,"%d",score);
	surface2=TTF_RenderText_Solid(font,text,color2);
	value=SDL_CreateTextureFromSurface(render,surface2);
 				up=0;
 				down=left=right=0;
 				back=0;
 			dead=0;
 			}
		}
	}
		}
		if((score>speed_point)&&!eaten){
		check_speed=1;
			SDL_RenderCopy(render,speed_ball,0,&speed_rect);
		
		}
				if(SDL_HasIntersection(&speed_rect,&snake)&&!eaten&& check_speed){
						speed=2;
						int valid=1;
						check_speed=0;
						speed_point+=13;;
			while(valid){
			speed_rect.x=sizze*6;
			speed_rect.x=sizze*6;
			if(!SDL_HasIntersection(&speed_rect,&frt)&&!SDL_HasIntersection(&speed_rect,&pit[index])&&!SDL_HasIntersection(&speed_rect,&tlp_rect[phase[0]])){
				valid=0;
			}
			}
				eaten=1;
				}
		if(score>speed_point&& eaten==1){
			eaten=0;
			
		}
		//✨✨✨✨💥💥💥
		SDL_RenderPresent(render);
		if(speed==2)speed_limit--;
		if(speed_limit==1){
			speed=1;
			speed_limit=100;
		}
		SDL_Delay(delay);
		if(branch==1) break;
		if(branch==2&&!dead){
			if(fall){
				tail[0]=u;
				tail[1]=v;
				snake.x=u;
				snake.y=v;
			}
			else{
		tail[1]=snake.x;
		tail[0]=snake.y;
			}
			if(branch!=3){
 while (SDL_PollEvent(&e)){
 	if(e.type==SDL_FINGERDOWN){
 		drag=1;
 		startx=e.tfinger.x*w;
 		starty=e.tfinger.y*h;
 		if(startx>=pause_rect.x&&startx<=pause_rect.x+pause_rect.w&&starty>=pause_rect.y&&starty<=pause_rect.y+pause_rect.h)branch=3;
 }
 if(e.type==SDL_FINGERUP){
 	if(drag){
 		drag=0;
 	endx=e.tfinger.x*w;
 	endy=e.tfinger.y*h;
 	int dx=endx-startx;
 	int dy=endy-starty;
 	if(abs(dx)>abs(dy)){
 	if(dx>50){
 		left=up=down=0;
 		right=1;
 	}
 	if(dx<-50){
 		right=up=down=0;
 		left=1;
 	}
 	}
 	else{
 
 	 if(dy<-50){
 		right=left=down=0;
 		up=1;
 		
 	}
 	else	if(dy>50){
 		left=right=up=0;
 		down=1;
 	}
 	}
 	}
 }
 
 }
			}
	if(skip>0)skip--;
	if(branch==1){
			up=0;
 				down=0;
 				left=0;
 				right=0;
	}
	if(!fall){
	for(int i=0;i<speed;i++){
 if(down){
 	snake.y+=size/2;
 	fresh=0;
 }
 if(snake.y>h-(size*1.5))dead=1;
 if(right){
 	snake.x+=size/2;
 	fresh=0;
 }
 if(snake.x>w-(size*2))dead=1;
 if(left){
 	snake.x-=size/2;
 	fresh=0;
 }
 if(snake.x<size)dead=1;
 if(!fresh){
 if(up)snake.y-=size/2;

 }
 if(snake.y<size*4)dead=1;
	}
	}
	if (SDL_HasIntersection(&frt,&snake)){
			int valid=1;
			while(valid){
				int ran1=rand()%(box_in_width-3)+1;
			frt.x=sizze*ran1;
			int ran=rand()%box_in_height;
			if(ran<4)ran+=4;
	frt.y=sizze*ran;
	for(int i=0;i<=back;i+=2){
		if(frt.x==tail[i]&&frt.y==tail[i+1]){
			valid=-1;
		}
	}
	if(valid==-1)valid=1;
	else {
		valid=0;
	}
			}
	
	 ran=rand()%2;
	
	if(!fall)back+=2;

	tail.resize(back+2);
	score++;
	if(score>HighScore){
		file=fopen("recents.txt","w");
		HighScore=score;
		fprintf (file,"%d",score);
		fclose (file);
	}
	skip=1;
	Mix_PlayChannel(-1,bite,0);
	sprintf(text,"%d",score);
	surface2=TTF_RenderText_Solid(font,text,color2);
	value=SDL_CreateTextureFromSurface(render,surface2);
		}

		
			num=index;
			if(fall){
					for(int i=back;i>=0;i-=2){
	
		
			tail[i]=tail[i-2];
			tail[i+1]=tail[i-1];
			tail[i-2]=u;
tail[i-1]=v;
if(tail[back]==u&&tail[back+1]==v){
					dead=1;
					delay=100;
					fall=0;
}
					}
	}else{
			for(int i=back;i>=0;i-=2){
	
			tail[i]=tail[i-2];
			tail[i+1]=tail[i-1];
	}
	}
	if(increase){
		frt.w++;
		frt.h++;
		if(frt.w==50){
			 decrease=1;
			 increase=0;
		}
	}
	if(decrease){
		frt.w--;
		frt.h--;
		if(frt.w==25){
			increase=1;
			decrease=0;
		}
	}
	}
	// Set Teleportation door

	}//if 2
}//branch 2;
}//main looop
}