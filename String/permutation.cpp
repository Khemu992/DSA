
#include<bits/stdc++.h>
using namespace std;

vector < string > ans;
void
recursion (string s, int pos)
{
  static int flag[3] = { 0 };
  static string res (3, '0');
  int i;
  if (s.size () == pos)
	{
	  ans.push_back (res);

	  return;
	}

  for (i = 0; i < s.size (); i++)
	{
	  if (flag[i] == 0)
		{
		  res[pos] = s[i];
		  flag[i] = 1;
		  pos++;
		  recursion (s, pos);
		  flag[i] = 0;
		  pos--;
		}
	}
  return;
}

int
main ()
{
  string s = "bac";
  recursion (s, 0);

  sort (ans.begin (), ans.end ());

  for (int i = 0; i < ans.size (); i++)
	{
	  for (int j = 0; j < ans[0].size (); j++)
		cout << ans[i][j] << " ";
	  cout << endl;
	}
  string c = "cab";
  if (c == ans[ans.size () - 1])
	cout << "next permutation is " << ans[0] << endl;
  else
	{
	  for (int i = 0; i < ans.size () - 1; i++)
		{
		  if (ans[i] == c)
			cout << "Next per is " << ans[i + 1];

		}
	}
  return 0;
}
