# include <iostream>

using namespace std;

int main(int argt, char* argv[])
{
	int x;
	cin >> x;
	for (int i1 = 0; i1 < 10; i1++)
	{
		for (int i2 = 0; i2 < 10; i2++)
		{
			for (int i3 = 0; i3 < 10; i3++)
			{
				for (int i4 = 0; i4 < 10; i4++)
				{
					for (int i5 = 0; i5 < 10; i5++)
					{
						for (int i6 = 0; i6 < 10; i6++)
						{
							if (i1 + i2 + i3 == i4 + i5 + i6 && i1 + i2 + i3 == x)
							{
								cout << i1 << i2 << i3 << i4 << i5 << i6 << " ";
							}

						}
					}
				}
			}
		}

	}

	return EXIT_SUCCESS;
}