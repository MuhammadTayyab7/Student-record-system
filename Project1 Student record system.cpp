#include<iostream>
#include <string>
#include<iomanip>
using namespace std;
int main()
{
	const int size = 100;
	string names[size] = { "" };
	string temp;
	int choice = 1, del, check, S;
	int Roll_no[50], Age[50], Semester[50], store;
	int stud, age, semester, count = 0;
	double CGPA[50], cgpa;
	int loop = 2;

	cout << "=======================================================================================================================" << endl;
	cout << "                                            [ Student Record System ]                                                  " << endl;
	while (choice != 0)
	{
		cout << "=======================================================================================================================" << endl;
		cout << "\n";
		cout << "    ********** MENU **********" << endl;
		cout << "    Press 1 to Add New Student" << endl;
		cout << "    Press 2 to Delete a student" << endl;
		cout << "    Press 3 to Search a student" << endl;
		cout << "    Press 4 to Display all students" << endl;
		cout << "    Press 5 to sort students according to their Roll No." << endl;
		cout << "    Press 0 to EXIT system" << endl;
		cout << "    Enter your choice: ";
		cin >> choice;
		cout << "\n\n";
		cout << "=======================================================================================================================" << endl;
		if (choice == 1)  //add a new student
		{
			for (int i = 0; i < loop; i++)
			{
				if (count < loop)
				{
					cout << "Enter student Roll N0. : ";
					cin >> stud;
					Roll_no[i] = stud;

					cout << "Enter student name : ";
					cin.ignore();
					getline(cin, names[i]);


					cout << "Enter student age : ";
					cin >> age;
					if (age > 16 && age <= 300)
						Age[i] = age;
					else
					{
						cout << "Invalid age (Enter Age between 16 to 30)  :(" << endl;
						cout << "Please enter age again : ";
						cin >> age;
						Age[i] = age;
					}
					cout << "Enter your Semester : ";
					cin >> semester;
					if (semester > 0 && semester <= 8)
						Semester[i] = semester;
					else
					{
						cout << "Invalid Semester(Enter semester between 1 to 8)  :(" << endl;
						cout << "Please enter semester again : ";
						cin >> semester;
						Semester[i] = semester;
					}

					cout << "Enter CGPA of a student : ";
					cin >> cgpa;
					cout << "\n";
					if (cgpa > -1 && cgpa < 5)
						CGPA[i] = cgpa;
					else
					{
						cout << "Invalid CGPA :(" << endl;
						cout << "Please enter CGPA again : ";
						cin >> cgpa;
						CGPA[i] = cgpa;
					}
					count++;
				}
				else
				{
					cout << "There is no space for new student" << endl;
					break;
				}
			}
		}
		if (choice == 2) //deleting students
		{
			cout << "Enter which student you want to delete :";
			cin >> del;
			for (int l = 0; l < loop; l++)
			{
				if (del == Roll_no[l])
					check = l;
			}
			for (int k = check; k < loop; k++)
			{
				for (int l = loop; l > loop - 1; l--)
				{
					Roll_no[k] = Roll_no[k + 1];
					Roll_no[l] = '\0';
					names[k] = names[k + 1];
					names[l] = '\0';
					Age[k] = Age[k + 1];
					Age[l] = '\0';
					Semester[k] = Semester[k + 1];
					Semester[l] = '\0';
					CGPA[k] = CGPA[k + 1];
					CGPA[l] = '\0';
				}
				count--;
			}
			for (int q = 0; q < loop; q++)
			{
				for (int s = q + 1; s < loop; s++)
				{
					if (Roll_no[q] > Roll_no[s])
					{
						store = Roll_no[q];
						Roll_no[q] = Roll_no[s];
						Roll_no[s] = store;

						temp = names[q];
						names[q] = names[s];
						names[s] = temp;

						store = Semester[q];
						Semester[q] = Semester[s];
						Semester[s] = store;

						store = Age[q];
						Age[q] = Age[s];
						Age[s] = store;

						store = CGPA[q];
						CGPA[q] = CGPA[s];
						CGPA[s] = store;
					}
				}
			}
			cout << "Student and their record successfully deleted....." << endl;
			cout << "\n";
		}
		if (choice == 3)
		{
			cout << "Enter Roll No. to find student and their data : ";
			cin >> S;
			cout << "\n";
			cout << " Roll No# \t\t Student Name \t\t\t Age \t\t Semester \t\t CGPA" << endl;
			for (int b = 0; b < loop; b++)
			{
				if (S == Roll_no[b])
				{
					cout << " " << Roll_no[b] << "\t\t\t" << setw(8) << names[b] << "\t\t" << setw(11) << Age[b] << "\t\t" << setw(5) << Semester[b] << "\t\t" << " " << setw(10) << CGPA[b] << "\n";
					break;
				}
				if (b == loop - 1)
				{
					cout << "Student not found...:(" << endl;
				}
			}
		}
		if (choice == 4)  //Display all students
		{
			cout << " Roll No# \t\t Student Name \t\t\t Age \t\t Semester \t\t CGPA" << endl;
			for (int x = 0; x < loop; x++)
			{
				cout << " " << Roll_no[x] << "\t\t\t" << setw(8) << names[x] << "\t\t" << setw(11) << Age[x] << "\t\t" << setw(5) << Semester[x] << "\t\t" << " " << setw(10) << CGPA[x] << "\n";

			}
		}
		if (choice == 5)// Shot students according their Roll No.
		{
			for (int v = 0; v < loop; v++)
			{
				for (int p = v + 1; p < loop; p++)
				{
					if (Roll_no[v] > Roll_no[p])
					{
						store = Roll_no[v];
						Roll_no[v] = Roll_no[p];
						Roll_no[p] = store;

						temp = names[v];
						names[v] = names[p];
						names[p] = temp;

						store = Semester[v];
						Semester[v] = Semester[p];
						Semester[p] = store;

						store = Age[v];
						Age[v] = Age[p];
						Age[p] = store;

						store = CGPA[v];
						CGPA[v] = CGPA[p];
						CGPA[p] = store;
					}
				}
			}
			cout << " Successfully shorted....:)" << endl;
			cout << " Press 4 to daisplay." << endl;
			cout << "\n";
		}
	}
	cout << "=======================================================================================================================" << endl;
	cout << "  Thank you for using system.......:)" << endl;
	cout << "\n\n";
	cout << "                         System was developed by : Muhammad Tayyab" << endl;
	cout << "=======================================================================================================================" << endl;
	system("pause");
	return 0;
}