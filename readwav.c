#include <stdio.h>
#include <stdlib.h>

typedef struct wave
{
	char ChunkID[5];
	long int ChunkSize;
	char Format[5];
	char Subchunk1ID[4];
	long int Subchunk1Size;
	short int AudioFormat;
	short int NumChannels;
	long int SampleRate;
	long int ByteRate;
	short int BlockAlign;
	short int BitsPerSample;
	char Subchunk2ID[5];
	long int Subchunk2Size;
	short int *data;
}WAVE;

int main(int argc, char const *argv[])
{
	FILE *sin;
	WAVE sin_deconstructed;
	int i, x = 0;
	sin = fopen("/home/kobi/Dropbox/MATLAB/sin.wav", "rb");
	if (sin==NULL)
	{
		printf("Couldn't open:\n");
		exit(1);
	}
	
	fread(sin_deconstructed.ChunkID, sizeof(char), 4, sin);
	fread(&sin_deconstructed.ChunkSize, sizeof(int), 1, sin);
	fread(sin_deconstructed.Format, sizeof(char), 4, sin);
	fread(sin_deconstructed.Subchunk1ID, sizeof(char), 3, sin);

		
	/*
	for (i = 0; i < 22;i++)
	{
		x = fgetc(sin);
		printf("%.2X ", x);
	}
	*/
	putchar('\n');
	return(0);
}