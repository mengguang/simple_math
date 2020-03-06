#include <ctime>
#include <iostream>
#include <string>
#include "rang.hpp"

using namespace std;
using namespace rang;

const int sum = 0;
const int sub = 1;

const int total_questions = 10;

const int op_sum_max_result = 20;
const int op_sum_min_result = 2;

const int op_sub_max_number_first = 20;
const int op_sub_min_number_first = 5;

int main()
{
	try
	{
		const auto seed = (unsigned int)time(nullptr);
		const auto start_time = time(nullptr);
		srand(seed);
		auto score = total_questions;
		for (auto i = 0; i < total_questions; i++)
		{
			cout << "Question " << i + 1 << ":" << endl;
			const auto op = rand() % 2;

			auto x = 0;
			auto y = 0;

			if (op == sum)
			{
				const auto sum_result = rand() % (op_sum_max_result - op_sum_min_result) + op_sum_min_result;
				x = rand() % (sum_result - 1) + 1;
				y = sum_result - x;
			}
			if (op == sub)
			{
				x = rand() % (op_sub_max_number_first - op_sub_min_number_first) + op_sub_min_number_first;
				y = rand() % (x - 1) + 1;
			}

			auto answer = 0;
			while (true)
			{
				if (op == sum)
				{
					cout << x << " + " << y << " = ";
					answer = x + y;
				}
				if (op == sub)
				{
					cout << x << " - " << y << " = ";
					answer = x - y;
				}

				string user_answer;
				std::getline(cin, user_answer);
				if (user_answer.empty())
				{
					cout << fg::red << "Error: empty input, please try again." << endl << fg::reset;
					continue;
				}
				auto user_answer_i = 0;
				try
				{
					user_answer_i = stoi(user_answer);
				}
				catch (exception& e)
				{
					cout << e.what() << endl;
					cout << fg::red << "Error: invalid input, please try again." << endl << fg::reset;
					continue;
				}

				if (user_answer_i == answer)
				{
					cout << fg::green << "Congratulations, you are right!" << endl << fg::reset;
					break;
				}
				else
				{
					cout << fg::red << "Sorry, but you are wrong, please try again." << endl << fg::reset;
					score--;
					continue;
				}
			}
		}
		const auto end_time = time(nullptr);
		cout << fg::blue << "Your final score: " << score << "." << endl << fg::reset;
		cout << fg::blue << "Total time used: " << end_time - start_time << " seconds." << endl << fg::reset;
		(void)getchar();
	}
	catch (exception& e)
	{
		cerr << e.what() << endl;
	}
	return 0;
}
