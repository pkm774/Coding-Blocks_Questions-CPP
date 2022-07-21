#include<bits/stdc++.h>
using namespace std ;
int main()
{
	int n , arr[1000] , target ;

	cin >> n ;

	for ( int f = 0 ; f <= n-1 ; f ++ )
	{
		cin >> arr[f] ;
	}

	cin >> target ;

	sort( arr , arr + n) ;



	int i = 0 ;
	while ( i <= n-2 )
	{


		int j = i + 1 ;

		int k = n-1 ;

		while ( j < k )
		{


			if (arr[i] + arr[j] + arr[k]  == target  )
			{
				cout << arr[i] <<", " << arr[j] <<" and " << arr[k]<<endl ;

			}

			else if ( arr[i] + arr[j] + arr[k]  < target)
			{
				++j ;
			}

			else if ( arr[i] + arr[j] + arr[k]  > target )
			{
			    --k ;
			}
			++j ; --k ;
			}
	i = i + 1 ;
	}
return 0 ;
}
