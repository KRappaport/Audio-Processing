#include <stdio.h>
#include <stdlib.h>

typedef struct wave
{
	char ChunkID[5];
	long int ChunkSize;
	char Format[5];
	char Subchunk1ID[5];
	long int Subchunk1Size;
	short int AudioFormat;
	short int NumChannels;
	long int SampleRate;
	long int ByteRate;
	short int BlockAlign;
	short int BitsPerSample;
	char Subchunk2ID[5];
	long int Subchunk2Size;
	short int *data_2;
	int *data_4;
}WAVE_FILE;

int main(int argc, char const *argv[])
{
	FILE *sin;
	WAVE_FILE sin_deconstructed;
	int data_size;
	sin = fopen("sin.wav", "rb");
	if (sin==NULL)
	{
		printf("Couldn't open:\n");
		exit(1);
	}

	fread(sin_deconstructed.ChunkID, sizeof(char), 4, sin);
	fread(&sin_deconstructed.ChunkSize, sizeof(int), 1, sin);
	fread(sin_deconstructed.Format, sizeof(char), 4, sin);
	fread(sin_deconstructed.Subchunk1ID, sizeof(char), 4, sin);
	fread(&sin_deconstructed.Subchunk1Size, sizeof(int), 1, sin);
	fread(&sin_deconstructed.AudioFormat, sizeof(short), 1, sin);
	fread(&sin_deconstructed.NumChannels, sizeof(short), 1, sin);
	fread(&sin_deconstructed.SampleRate, sizeof(int), 1, sin);
	fread(&sin_deconstructed.ByteRate, sizeof(int), 1, sin);
	fread(&sin_deconstructed.BlockAlign, sizeof(short), 1, sin);
	fread(&sin_deconstructed.BitsPerSample, sizeof(short), 1, sin);
	fread(sin_deconstructed.Subchunk2ID, sizeof(char), 4, sin);
	fread(&sin_deconstructed.Subchunk2Size, sizeof(int), 1, sin);

	data_size = sin_deconstructed.Subchunk2Size/(int)sin_deconstructed.BlockAlign;

	sin_deconstructed.data_2 = (short*)malloc(sizeof(short)*data_size);
	if (sin_deconstructed.data_2==NULL) {
		perror("Error");
		exit(1);
	}


	fread(sin_deconstructed.data_2, sizeof(short), data_size, sin);

	printf("%d\t%d\t%d\t%d\n", sin_deconstructed.data_2[0], sin_deconstructed.data_2[1], sin_deconstructed.data_2[62], sin_deconstructed.data_2[1000]);

	putchar('\n');
	return(0);
}
