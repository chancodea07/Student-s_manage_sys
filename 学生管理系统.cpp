#include"data_st.h"
#include"feature.h"
int main()
{
	struct Node* list = createList();
	readInfoFromFile("student.txt", list);
	while (1)
	{
		systemMenu();
		keyDown(list);
		system("pause");
		system("cls");
	}
	return 0;
}

