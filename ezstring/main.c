#include <stdio.h>

#include "ezstring.h"

String read_string();
String read_string_max(int max);

int main() {
	String s = string("my string");

	printf("%s \n", s->cstr);



	String sizedString = string_sized(50);

	expand(sizedString, 255);

	sprintf(sizedString->cstr, "sized strings are %s and 2+3=%d and my other string is %s", "awesome", 5, s->cstr);
	printf("%s \n", sizedString->cstr);

	delete(s);
	delete(sizedString);



	printf("Please enter your username: ");
	String username = read_string_max(255);
	printf("Welcome, %s\n", username->cstr);

	printf("Write a long text :");
	String long_str = read_string();
	printf("Your long text    :%s\n", long_str->cstr);


	system("PAUSE");
}

String read_string_max(int max) {
	String str_big = string_sized(max);

	scanf("%s", str_big->cstr);

	String str = copy(str_big);
	delete(str_big);

	return str;
}

String read_string() {
	static String str_big;
	
	if(str_big == NULL)
		str_big= string_sized(255*10);
	else
		clear(str_big);

	scanf("%s", str_big->cstr);

	String str = copy(str_big);

	return str;
}