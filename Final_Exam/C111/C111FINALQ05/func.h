#pragma once
#pragma once
#include <stdio.h>
#include <stdlib.h>
#define Initialize(...) __Initialize((init_args){__VA_ARGS__})
#define StringSlice(s, ...) __StringSlice(s, (slice_args){__VA_ARGS__})
#define StringCat(s, ...) __StringCat(s, (cat_args){__VA_ARGS__})
typedef struct
{
	const char* arr;
} init_args;
typedef struct
{
	int start;
	int end;
} slice_args;
typedef struct
{
	char* content;
	int size;
} string;
typedef struct
{
	const char* charArr;
	string str;
} cat_args;
void PushBack(string* s, const char addend)
{
	char* temp = realloc(s->content, (s->size + 2) * sizeof(char));
	if (temp == NULL)
	{
		puts("memory allocation failed!\n");
		return;
	}
	s->content = temp;
	s->content[s->size] = addend;
	s->size++;
	s->content[s->size] = '\0';
}
string __Initialize(init_args args)
{
	string s = { .content = calloc(1, sizeof(char)), .size = 0 };
	if (args.arr)
		for (int i = 0; args.arr[i]; i++)
			PushBack(&s, args.arr[i]);
	return s;
}
string ReadLine()
{
	char input;
	string s = Initialize(NULL);

	for (input = getchar(); input == '\n'; input = getchar())
		;
	for (; input != '\n'; input = getchar())
		PushBack(&s, input);
	return s;
}
string Read()
{
	char input;
	string s = Initialize(NULL);
	for (input = getchar(); input == '\n' || input == ' '; input = getchar())
		;
	for (; input != ' ' && input != '\n'; input = getchar())
		PushBack(&s, input);
	return s;
}
void PrintStringInfo(const string s)
{
	printf("Size: %d\nContent: ", s.size);
	for (int i = 0; s.content[i]; i++)
		putchar(s.content[i]);
	putchar('\n');
}
void PrintString(const string s)
{
	for (int i = 0; s.content[i]; i++)
		putchar(s.content[i]);
	putchar('\n');
}
string* StringSplit(const string s, const char separate, int* element)
{
	int index = 0;
	string* result = malloc(sizeof(string) * (index + 1));
	result[index] = Initialize(NULL);
	int start = 0;
	for (; s.content[start]; start++)
		if (s.content[start] != separate)
			break;
	for (int i = start; s.content[i]; i++)
	{
		if (s.content[i] == separate)
		{
			if (s.content[i + 1] == separate || s.content[i + 1] == '\0')
				continue;
			index++;
			result = realloc(result, sizeof(string) * (index + 1));
			result[index] = Initialize(NULL);
		}
		else
			PushBack(&result[index], s.content[i]);
	}
	*element = index + 1;
	return result;
}
void __StringCat(string* s, cat_args args)
{
	if (args.charArr)
	{
		for (int i = 0; args.charArr[i]; i++)
			PushBack(s, args.charArr[i]);
	}
	if (args.str.content)
	{
		for (int i = 0; args.str.content[i]; i++)
			PushBack(s, args.str.content[i]);
	}
}
int StringCompare(const string s1, const string s2)
{
	if (s1.size != s2.size)
		return s1.size > s2.size ? 1 : -1;
	for (int i = 0; s1.content[i]; i++)
		if (s1.content[i] != s2.content[i])
			return s1.content[i] > s2.content[i] ? 1 : -1;
	return 0;
}
int StringNCompare(const string s1, const string s2, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (!s1.content[i])
			return 1;
		if (!s2.content[i])
			return -1;
		if (s1.content[i] != s2.content[i])
			return s1.content[i] > s2.content[i] ? 1 : -1;
	}
	return 0;
}
string __StringSlice(const string s, slice_args args)
{
	int start = args.start ? args.start : 0;
	int end = args.end ? args.end : s.size;
	if (start > s.size - 1)
		start = s.size - 1;
	if (end > s.size)
		end = s.size;

	string result = Initialize(NULL);
	for (int i = start; i < end; i++)
		PushBack(&result, s.content[i]);
	return result;
}
string StringReverse(const string s)
{
	string result = Initialize(s.content);
	char temp;
	for (int start = 0, end = s.size - 1; start <= end; start++, end--)
	{
		temp = result.content[start];
		result.content[start] = result.content[end];
		result.content[end] = temp;
	}
	return result;
}
void StringFree(string* s)
{
	free(s->content);
	s->size = 0;
}
string StringReplace(const string origin, const string replacement, const string temp)
{
	string result = Initialize(NULL);
	for (int i = 0; i < origin.size; i++)
	{
		if (!StringNCompare(StringSlice(origin, i, i + replacement.size), replacement, replacement.size))
		{
			StringCat(&result, .str = temp.content);
			i += replacement.size - 1;
		}
		else
		{
			PushBack(&result, origin.content[i]);
		}
	}
	return result;
}
// The string length of name
#define LEN_NAME 50

// A structure represents the information of each student
struct student
{
	// The name string
	// Parameter: name (string)
	char name[LEN_NAME];

	// The score of English
	// Parameter: english (integer)
	int english;

	// The score of Math
	// Parameter: math (integer)
	int math;

	// The score of History
	// Parameter: history (integer)
	int history;

	// The score of Physics
	// Parameter: physics (integer)
	int physics;

	// Pointer to next student
	// Parameter: next (struct pointer)
	struct student* next;
};

/// <summary>
/// Convert the given CSV format string into a linked list using 'student' structure.
/// </summary>
/// <param name="data">The data string.</param>
/// <returns>The first node of the created linked list.</returns>
struct student* convert(char* data)
{
	int size;
	string* arr = StringSplit(Initialize(data), '\n', &size);
	struct student* head = malloc(sizeof(struct student));
	struct student** curr = &head;
	for (int i = 0; i < size; i++)
	{
		int n;
		string* convert_data = StringSplit(arr[i], ',', &n);
		struct student* temp = calloc(1, sizeof(struct student));
		for (int cnt = 0; convert_data[0].content[cnt]; cnt++)
			temp->name[cnt] = convert_data[0].content[cnt];
		temp->english = StoI(convert_data[1]);
		temp->math = StoI(convert_data[2]);
		temp->history = StoI(convert_data[3]);
		temp->physics = StoI(convert_data[4]);
		temp->next = NULL;
		*curr = temp;
		curr = &((*curr)->next);
	}
	return head;
}

/// <summary>
/// Calculate the total score of each student, and return the average of all total scores.
/// </summary>
/// <param name="node">The starter node of linked list.</param>
/// <returns>The average value.</returns>
float average(struct student* node)
{
	int cnt = 0;
	float avg = 0;
	for (struct student* i = node; i; i = i->next)
	{
		avg += (i->english);
		avg += (i->history);
		avg += (i->math);
		avg += (i->physics);
		cnt++;
	}
	return avg / cnt;
}

int StoI(string a)
{
	int cnt = 0;
	for (int i = 0; a.content[i]; i++)
	{
		cnt += a.content[i] - '0';
		cnt *= 10;
	}
	return cnt / 10;
}