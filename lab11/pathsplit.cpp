#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pathsplit.h"

char* substring(char* str, int start, int end) {
	int len = end - start;
	char* rc;

	rc = (char*)malloc((len + 1)*sizeof(char));

	if (rc == NULL) {
		exit(1);
	}
	memcpy(rc, str + start, len);
	rc[len] = 0;

	return rc;
}

void find_ext(char* basename, char** name, char** ext) {
	int len = strlen(basename), i = len;

	for (; basename[i] != '.'; i--) {}

	if (i <= 0) {
		i = len;
	}

	*name = substring(basename, 0, i);
	*ext = substring(basename, i, len);
}

void pathsplit(char* path, char* split[]) {
	char* basename = NULL;
	char* name = NULL;
	char* ext = NULL;
	int len = strlen(path), count = 0, first_char = 0, i;

	for (i = 0; i < len; i++) {
		if (path[i] == '/' || path[i] == '\\') {
			if (i == first_char) {
				first_char += 1;
				continue;
			}
			split[count] = substring(path, first_char, i);
			first_char = i + 1;
			count += 1;
		}
	}

	basename = substring(path, first_char, i);
	find_ext(basename, &name, &ext);
	split[count] = name;
	count += 1;
	split[count] = ext;
	count += 1;
	
	for (i = 0; i < count; i++) {
		printf("%s\n", split[i]);
		free(split[i]);
		split[i] = NULL;
	}
	free(basename);
}