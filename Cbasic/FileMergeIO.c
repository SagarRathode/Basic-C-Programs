#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

void combine_files(const char *directory_name, const char *output_filename) {
    DIR *dir;
    struct dirent *entry;
    FILE *outfile, *infile;
    char filepath[1024], ch;

    // Open the directory
    dir = opendir(directory_name);
    if (dir == NULL) {
        perror("Unable to open directory");
        exit(1);
    }

    // Open the output file
    outfile = fopen(output_filename, "w");
    if (outfile == NULL) {
        perror("Unable to create output file");
        exit(1);
    }

    // Loop over all files in the directory
    while ((entry = readdir(dir)) != NULL) {
        // Ignore . and .. (special directories)
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Construct the full file path
        snprintf(filepath, sizeof(filepath), "%s/%s", directory_name, entry->d_name);

        // Open the input file
        infile = fopen(filepath, "r");
        if (infile == NULL) {
            perror("Unable to open file");
            continue; // Skip this file and move to the next
        }

        // Read from the input file and write to the output file
        while ((ch = fgetc(infile)) != EOF) {
            fputc(ch, outfile);
        }

        fclose(infile); // Close the input file
    }

    closedir(dir);     // Close the directory
    fclose(outfile);   // Close the output file
}

int main() {
    char directory_name[256];
    char output_filename[256];

    // Get the directory name from the user
    printf("Enter the directory name: ");
    scanf("%255s", directory_name);

    // Get the output file name
    printf("Enter the output file name: ");
    scanf("%255s", output_filename);

    // Combine the files in the directory
    combine_files(directory_name, output_filename);

    printf("All files in directory '%s' combined into '%s'\n", directory_name, output_filename);

    return 0;
}

