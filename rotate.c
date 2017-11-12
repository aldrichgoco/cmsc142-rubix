#include <stdio.h>
#define N 3

/* 
CMSC 142 - RUBIX2D
STA.ANA, GOCO, ANTON
TO DO:
	Milestone 1:
		Read from input file
		Main Rotation
*/
		
void printCube(int cube[6*N][N]){
	int h,i,j;
	for(i = 0;i < 3;i++){
		printf("      ");
		for(j = 0;j < 3;j++){
			printf("%d ",cube[i][j]);
		}
		printf("\n");
	}

	for(h = 0;h < 3;h++){
		for(i = 3+h;i < 15+h;i+=3){
			for(j = 0;j < 3;j++){
				printf("%d ",cube[i][j]);
			}
		}
		printf("\n");
	}
		

	for(i = 15;i < 6*N;i++){
		printf("      ");
		for(j = 0;j < 3;j++){
			printf("%d ",cube[i][j]);
		}
		printf("\n");
	}
}

int getColorIndex(int color){
	switch(color){
		case 0:
			return 0;
		case 1:
			return 3;
		case 2:
			return 6;
		case 3:
			return 9;
		case 4:
			return 12;
		case 5:
			return 15;
	}
}
void * rotate_cube(int cube[6*N][N], int direction){
	/* THIS MODULE ONLY CONTAINS INNER ROTATE */
	/* TO DO : MAIN ROTATION */ 

	int color = 1; //ROTATE RED 
	int orig_matrix[3][3];
	int i,j,count;

	//create a copy of the original array
	int colorIndex = getColorIndex(1); //white
	for(i = colorIndex;i < (colorIndex + 3);i++){
		for(j = 0;j < 3;j++){
			orig_matrix[i-colorIndex][j] = cube[i][j];
		}
	}


	/*//print original array (basis)
	for(i = 0;i < 3;i++){
		for(j = 0;j < 3;j++){
			printf("%4d",orig_matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	*/
	if(direction = 1){ //clockwise
		count = 2;
		for(i =0;i < 3;i++){
			for(j=colorIndex;j < (colorIndex + 3);j++){
				cube[j][count] = orig_matrix[i][j-colorIndex]; 
			}
			count -= 1;
		}
	}
	else{
		//counterClockwise
		count = 2;
		for(i =colorIndex;i < (colorIndex + 3);i++){
			for(j=colorIndex;j < (colorIndex + 3);j++){
				cube[i][j-colorIndex] = orig_matrix[j-colorIndex][count];
			}
			count -= 1;
			printf("\n");
		}
	}
	printCube(cube);





	
}
int main(){
	int cube[6*N][N] =	{
		{0,0,0},
		{0,0,0},
		{0,0,0},
		{1,2,3},
		{3,2,1},
		{2,1,3},
		{2,2,2},
		{2,2,2},
		{2,2,2},
		{3,3,3},
		{3,3,3},
		{3,3,3},
		{4,4,4},
		{4,4,4},
		{4,4,4},
		{5,5,5},
		{5,5,5},
		{5,5,5}
	};

	rotate_cube(cube,0);		
}

