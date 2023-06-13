#include <iostream>
#include "clui.h"
#include <string.h>
using namespace std;

struct tarikh
{
	int month;
	int day;
};

struct task
{
	char *title = new char[100];
	char *exp = new char[400];
	int value;
	tarikh deadline;
};

void first_meno()
{
	save_cursor();
	change_color_rgb(0, 255, 0);
	int row = get_window_rows();
	int cols = get_window_cols();
	cursor_to_pos(row / 2, cols / 2 - 12);
	cout << "ARMAN IS LOADING";
	change_color_rgb(255, 0, 127);
	cursor_to_pos(row / 2, cols / 2 + 5);
	cout << ".............";
	delay(5000);

	clear_screen();
	reset_color();
	restore_cursor();
}

void meno()
{
	save_cursor();
	int col = get_window_cols();
	int row = get_window_rows();

	cursor_to_pos(1, 45);
	change_color_rgb(255, 255, 0);
	cout << "welcome to my first project";
	flush();
	reset_color();

	change_color_rgb(51, 255, 51);
	cursor_to_pos(2, 45);
	for (int i = 0; i < 27; i++)
	{
		if (i % 2 == 0)
			printf("*");
		else
			printf(" ");
		flush();
	}

	change_color_rgb(51, 255, 51);
	cursor_to_pos(3, 96);
	for (int i = 0; i < 23; i++)
		printf("-");
	flush();
	reset_color();

	change_color_rgb(204, 0, 102);
	cursor_to_pos(4, 96);
	cout << "make new task : M" << '\n';
	flush();

	cursor_to_pos(5, 96);
	cout << "view tasks : V" << '\n';
	flush();

	cursor_to_pos(6, 96);
	cout << "finish app : F" << '\n';
	flush();
	reset_color();

	change_color_rgb(51, 255, 51);
	cursor_to_pos(7, 96);
	for (int i = 0; i < 23; i++)
		printf("-");
	flush();
	reset_color();

	restore_cursor();
}

void make_task(task &task_arman, int &dafe)
{

	if (dafe == 0)
	{
		cursor_to_pos(5, 0);
	}
	else
		restore_cursor();

	cout << '\n';
	flush();
	cout << '\n';
	flush();

	delay(100);
	change_color_rgb(0, 0, 204);
	cout << "Enter title of task : ";
	flush();
	reset_color();
	change_color_rgb(0, 255, 127);
	cin.getline(task_arman.title, 100);
	reset_color();
	if (dafe == 0)
	{
		delay(100);
		change_color_rgb(0, 0, 204);
		cout << "sorry Enter it again : ";
		reset_color();
	}
	change_color_rgb(0, 255, 127);
	cin.getline(task_arman.title, 100);
	reset_color();
	while (strlen(task_arman.title) > 100)
	{
		cout << '\n';
		delay(100);
		change_color_rgb(0, 0, 204);
		cout << "invalid! try again : ";
		flush();
		reset_color();
		change_color_rgb(0, 255, 127);
		cin.getline(task_arman.title, 100);
		reset_color();
	}
	cout << '\n';
	flush();

	delay(100);
	change_color_rgb(0, 0, 204);
	cout << "Enter explanation : ";
	flush();
	reset_color();
	change_color_rgb(0, 255, 127);
	cin.getline(task_arman.exp, 400);
	reset_color();
	while (strlen(task_arman.exp) > 400)
	{
		cout << '\n';
		delay(100);
		change_color_rgb(0, 0, 204);
		cout << "invalid! try again : ";
		reset_color();
		flush();
		change_color_rgb(0, 255, 127);
		cin.getline(task_arman.exp, 400);
		reset_color();
	}
	cout << '\n';
	flush();

	delay(100);
	change_color_rgb(0, 0, 204);
	cout << "Enter value of task : ";
	flush();
	reset_color();
	change_color_rgb(255, 0, 127);
	cin >> task_arman.value;
	reset_color();
	while (task_arman.value > 10 || task_arman.value < 1)
	{
		cout << '\n';
		delay(100);
		change_color_rgb(0, 0, 204);
		cout << "invalid! try again : ";
		flush();
		reset_color();
		change_color_rgb(255, 0, 127);
		cin >> task_arman.value;
		reset_color();
	}
	cout << '\n';
	flush();

	delay(100);
	change_color_rgb(0, 0, 204);
	cout << "Enter the Deadline month : ";
	flush();
	reset_color();
	change_color_rgb(255, 0, 127);
	cin >> task_arman.deadline.month;
	reset_color();
	while (task_arman.deadline.month < 1 || task_arman.deadline.month > 12)
	{
		cout << '\n';
		delay(100);
		change_color_rgb(0, 0, 204);
		cout << "invalid! try again : ";
		flush();
		reset_color();
		change_color_rgb(255, 0, 127);
		cin >> task_arman.deadline.month;
		reset_color();
	}
	cout << '\n';
	flush();

	delay(100);
	change_color_rgb(0, 0, 204);
	cout << "Enter the Deadline day : ";
	flush();
	reset_color();
	change_color_rgb(255, 0, 127);
	cin >> task_arman.deadline.day;
	reset_color();
	while (task_arman.deadline.day < 1 || task_arman.deadline.day > 31)
	{
		cout << '\n';
		delay(100);
		change_color_rgb(0, 0, 204);
		cout << "invalid! try again : ";
		flush();
		reset_color();
		change_color_rgb(255, 0, 127);
		cin >> task_arman.deadline.day;
		reset_color();
	}
	cout << '\n';
	flush();

	save_cursor();
}

void sort(task *&arr, int n)
{
	for (int i = 1; i < n; i++)
	{
		task komaki = arr[i];
		int j = i;
		while (j > 0 && arr[j - 1].value < komaki.value)
		{
			arr[j] = arr[j - 1];
			j--;
		}
		arr[j] = komaki;
	}
}

void add_list(task *&list, int &tedad, task jadid)
{

	task *komaki = new task[tedad + 1];

	for (int i = 0; i < tedad; i++)
	{
		komaki[i] = list[i];
	}
	komaki[tedad] = jadid;

	sort(komaki, tedad + 1);

	delete[] list;
	list = komaki;
	tedad++;
}

void delete_task(task *&list, int &tedad, int andis_h)
{
	task *komaki = new task[tedad - 1];

	for (int i = 0; i < andis_h; i++)
	{
		komaki[i] = list[i];
	}

	for (int i = andis_h; i < tedad - 1; i++)
	{
		komaki[i] = list[i + 1];
	}

	delete[] list;
	list = komaki;
	tedad--;
}

void view_tasks(task *&list, int &tedad)
{

	restore_cursor();

	cout << '\n';
	flush();
	cout << '\n';
	flush();

	delay(1000);

	for (int i = 0; i < tedad; i++)
	{
		change_color_rgb(0, 255, 255);
		printf("title of task %d : %s ", i + 1, list[i].title);
		cout << '\n'
			 << '\n';
		flush();
		reset_color();

		delay(100);
		change_color_rgb(0, 255, 255);
		printf("value of task %d : %d ", i + 1, list[i].value);
		cout << '\n'
			 << '\n';
		flush();
		reset_color();

		delay(100);
		change_color_rgb(0, 255, 255);
		printf("deadline of task %d is %d/%d ", i + 1, list[i].deadline.month, list[i].deadline.day);
		cout << '\n'
			 << '\n';
		flush();
		reset_color();

		change_color_rgb(51, 255, 51);
		for (int i = 0; i < 27; i++)
		{
			if (i % 2 == 0)
				printf("+");
			else
				printf(" ");
			flush();
		}
		cout << '\n';
	}
	reset_color();

	change_color_rgb(0, 0, 255);
	delay(100);
	cout << "for intring Enter number N : " << '\n'
		 << '\n';
	cout << "for back Enter B : " << '\n'
		 << '\n';
	cout << "for exit Enter F : ";
	flush();
	reset_color();

	change_color_rgb(255, 0, 127);
	char option;
	cin >> option;
	int shomare;
	if (option == 'N')
	{
		reset_color();
		change_color_rgb(0, 255, 255);
		cout << "Enter number of the task : ";
		cin >> shomare;
		while (shomare > tedad || shomare < 1)
		{
			change_color_rgb(255, 0, 0);
			cout << endl;
			cout << "invalid enter number again : ";
			cin >> shomare;
			reset_color();
		}

		cout << '\n';
		reset_color();
	}

	if (option == 'B')
	{
		return;
	}

	if (option == 'F')
	{
		reset_color();
		exit(0);
	}

	reset_color();

	change_color_rgb(255, 255, 51);
	for (int i = 0; i < 27; i++)
	{
		if (i % 2 == 0)
			printf("*");
		else
			printf(" ");
		flush();
	}
	cout << '\n';
	reset_color();

	delay(1000);
	change_color_rgb(0, 255, 0);
	printf("title of task %d : %s ", shomare, list[shomare - 1].title);
	cout << '\n'
		 << '\n';
	flush();

	delay(100);
	printf("exp of task %d : %s", shomare, list[shomare - 1].exp);
	cout << '\n'
		 << '\n';
	flush();

	delay(100);
	printf("value of task %d : %d ", shomare, list[shomare - 1].value);
	cout << '\n'
		 << '\n';
	flush();

	delay(100);
	printf("deadline of task %d is %d/%d ", shomare, list[shomare - 1].deadline.month, list[shomare - 1].deadline.day);
	cout << '\n'
		 << '\n';
	flush();
	reset_color();

	change_color_rgb(255, 255, 51);
	for (int i = 0; i < 27; i++)
	{
		if (i % 2 == 0)
			printf("*");
		else
			printf(" ");
		flush();
	}
	cout << '\n';
	reset_color();

	change_color_rgb(0, 0, 255);
	cout << "for back press B" << '\n'
		 << '\n';
	cout << "for finish press F" << '\n'
		 << '\n';
	cout << "for deleting this task press D";
	flush();
	reset_color();

	char dastoor = getch();
	if (dastoor == 'D')
	{
		delete_task(list, tedad, shomare - 1);
		cout << '\n';
		change_color_rgb(255, 0, 0);
		printf("task %d deleted \n", shomare);
		reset_color();
	}
	save_cursor();
	if (dastoor == 'B')
	{
		view_tasks(list, tedad);
	}
	if (dastoor == 'F')
		exit(0);
}

int main()
{
	init_clui();
	int tedad = 0, dafe = -1;
	task *list = new task[tedad];

	first_meno();
	meno();

	while (true)
	{

		dafe++;
		change_color_rgb(153, 255, 255);
		cout << "order from guid : ";
		reset_color();
		char voroodi = getch();

		task task_arman;
		switch (voroodi)
		{
		case 'M':
			make_task(task_arman, dafe);
			add_list(list, tedad, task_arman);
			break;
		case 'V':
			view_tasks(list, tedad);
			break;
		case 'F':
			return 0;
			break;

		default:
			change_color_rgb(255, 0, 0);
			cout << "invalid !" << '\n';
			reset_color();
			break;
		}
	}
	quit();
	return 0;
}
