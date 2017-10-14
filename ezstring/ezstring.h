#ifndef EZ_STRING
#define EZ_STRING

#include <string.h>
#include <stdlib.h>

#define GLOBAL_STRING(size) (String)&( (string_s){ char [size], size } )

typedef struct
{
	char * cstr;
	int size;
} string_s;

typedef string_s* String;


void clear(String str) {
	str->cstr[0] = '\0';
}


String string_sized(unsigned int size) {
	String str = (String)malloc(sizeof(string_s));
	str->size = size;
	str->cstr = (char*)malloc(sizeof(char)*(str->size));

	clear(str);

	return str;
}

String string(const char* cstr) {
	String str = string_sized((unsigned int)strlen(cstr)+1);

	strcpy(str->cstr, cstr);
	return str;
}

String copy(String s) {
	return string(s->cstr);
}

char* rest(String str) {
	return str->cstr + strlen(str) - 1;
}

void expand(String str, int size) {
	str->size += size;
	char* newCstr= (char*)malloc(sizeof(char)*(str->size));
	strcpy(newCstr, str->cstr);

	free(str->cstr);

	str->cstr = newCstr;
}

unsigned int len(String s) {
	return s->size - 1;
}

void delete(String str) {
	if (str == NULL)
		return;

	if (str->cstr != NULL) {
		free(str->cstr);
	}

	free(str);
}

#endif