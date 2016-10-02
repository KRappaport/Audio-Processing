#include <stdio.h>
#include <stdlib.h>


int main() {

    int decimation_factor, new_data_size, original_data_size;
    FILE *dec_audio;
    WAVE_FILE *original_wave, wave_decimated;

    original_data_size = wave_deconstructed.Subchunk2Size/(int)wave_deconstructed.BlockAlign;
    new_data_size = original_data_size - (original_data_size/decimation_factor);

    wave_decimated.data = (short*)malloc(sizeof(short)*new_data_size);

    return(0);
}
