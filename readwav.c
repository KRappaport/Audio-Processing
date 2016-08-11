#include <stdio.h>
#include <stdlib.h>

typedef struct wave
{
	char ChunkID[5];
	int ChunkSize;
	char Format[5];
	char Subchunk1ID[5];
	int Subchunk1Size;
	short int AudioFormat;
	short int NumChannels;
	int SampleRate;
	int ByteRate;
	short int BlockAlign;
	short int BitsPerSample;
	char Subchunk2ID[5];
	int Subchunk2Size;
	short int *data_2;
	short int **data_4;
}WAVE_FILE;

int main(int argc, char const *argv[])
{
	FILE *audio;
	WAVE_FILE wave_deconstructed;
	int data_size, i, k;
	audio = fopen("Flute.wav", "rb");
	if (audio==NULL)
	{
		printf("Couldn't open:\n");
		exit(1);
	}

	fread(wave_deconstructed.ChunkID, sizeof(char), 4, audio);
	fread(&wave_deconstructed.ChunkSize, sizeof(int), 1, audio);
	fread(wave_deconstructed.Format, sizeof(char), 4, audio);
	fread(wave_deconstructed.Subchunk1ID, sizeof(char), 4, audio);
	fread(&wave_deconstructed.Subchunk1Size, sizeof(int), 1, audio);
	fread(&wave_deconstructed.AudioFormat, sizeof(short), 1, audio);
	fread(&wave_deconstructed.NumChannels, sizeof(short), 1, audio);
	fread(&wave_deconstructed.SampleRate, sizeof(int), 1, audio);
	fread(&wave_deconstructed.ByteRate, sizeof(int), 1, audio);
	fread(&wave_deconstructed.BlockAlign, sizeof(short), 1, audio);
	fread(&wave_deconstructed.BitsPerSample, sizeof(short), 1, audio);
	fread(wave_deconstructed.Subchunk2ID, sizeof(char), 4, audio);
	fread(&wave_deconstructed.Subchunk2Size, sizeof(int), 1, audio);


	if (wave_deconstructed.BitsPerSample == 16) {

		data_size = wave_deconstructed.Subchunk2Size/(int)wave_deconstructed.BlockAlign;

		if (wave_deconstructed.BlockAlign == 2) {
			wave_deconstructed.data_2 = (short*)malloc(sizeof(short)*data_size);
			if (wave_deconstructed.data_2==NULL) {
				perror("Error");
				exit(1);
			}
			fread(wave_deconstructed.data_2, sizeof(short), data_size, audio);

		}

		else if (wave_deconstructed.BlockAlign == 4){
			wave_deconstructed.data_4 = (short**)malloc(sizeof(short)*wave_deconstructed.NumChannels);
			for (i = 0; i < wave_deconstructed.NumChannels; i++) {
				wave_deconstructed.data_4[i] = (short*)malloc(sizeof(short)*data_size);
			}
			for (i = 0; i < data_size; i++) {
				for (k = 0; k < wave_deconstructed.NumChannels; k++) {
					fread(&wave_deconstructed.data_4[k][i], sizeof(short), 1, audio);
				}
			}

		}
	}


	fclose(audio);

	putchar('\n');
	return(0);
}
