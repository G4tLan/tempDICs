#include <stdlib.h>
#include <stdio.h>

#define factor 0.1f


void setKArrayToZeros(int *Data, int numElements ){
/*
This function accept a K dimensional array of integers with unknown dimension lengths
*/	
	//int *ptr = (int*)arr; //pointer pointing to zeroeth element
	
	//int dem =sizeof(arr)/sizeof(*Data);
	int newValue = 0;
	for(int i = 0 ; i<numElements; i++ ){
		//printf("%d \n", *Data );
		*Data = newValue;
		Data++;
	}	
}

void setTenPercentToOnes(int *Data, int numElements ){
/*
This function accept a  K dimensional array of integers with unknown dimension lengths
*/	
	//int *ptr = (int*)arr; //pointer pointing to zeroeth element
	
	//int dem =sizeof(arr)/sizeof(*Data);
	
	int maxPoints = factor*numElements;
	int newValue = 1;
	for(int i = 0 ; i<maxPoints; i++ ){
		//printf("%d \n", *Data );
		*Data = newValue;
		Data++;
	}	
}

void printArray(int *Data, int numElements ){
	for(int i = 0 ; i<numElements; i++ ){
		printf("%d \n", *Data);
		Data++;
	}	
	printf("\n");
}

void findFivePercent(int *Data, int numElements, int * bounds, int lengthOfBounds){
	
	
	int count = 0;
	int *P1 = Data;
	int randPos = rand()%numElements;
	 randPos = 7;
	P1 += randPos;
	int *P2 = Data;
	int iter = 0;
	for(int i =0; i <  lengthOfBounds; i++){
		
		iter = numElements/(*(bounds + i));
		
		while(P2 < P1){
			P2 += iter;
			if(P1 >= P2 ){
				count++;
			} else {
				numElements = iter;
				P2 -= iter;
				break;
			}
		}
		printf("%d ", count );
		count = 0;
	}
	printf("\n");
}


int main(){

	
	int arr[2][3][4][2] = {
                        {
                          {
                            {1,48},{2,3},{4,5},{6,7}
                          },
                          {
                            {8, 9},{10, 11},{12, 13},{14,15}
                          },
                          {
                            {16, 17},{18, 19},{20, 21},{22,23}
                          }
                       },
                       {
                         {
                           {24,25},{26,27},{28,29},{30,31}
                         },
                         {
                           {32, 33},{34, 35},{36, 37},{38,39}
                         },
                         {
                           {40, 41},{42, 43},{44, 45},{46,47}
                         }
                      }
                    };
					
				
	//int arr [3][3] = {{1,2,3},{4,5,6},{7,8,9}};
	int *ptr = (int*)arr; //pointer pointing to zeroeth element
	int dem =sizeof(arr)/sizeof(*ptr);
	
	printArray(ptr,dem);
	setKArrayToZeros(ptr,dem);
	printArray(ptr,dem);
	setTenPercentToOnes(ptr,dem);
	printArray(ptr,dem);

	

	printf("find five percent \n");
	int Bounds[4] = {2,3,4,2};
	int *bounds = (int*)Bounds;
	int lengthOfBounds = sizeof(Bounds)/sizeof(Bounds[0]);
	printf("dem %d", dem);
	printf("lob %d  \n", lengthOfBounds);
	
	findFivePercent(ptr, dem, bounds ,lengthOfBounds);
	return 0;
}
