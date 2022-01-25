#ifndef BINARYSEARCH
#define BINARYSEARCH
// https://practice.geeksforgeeks.org/problems/capacity-to-ship-packages-within-d-days/1?utm_source=gfgpractice&utm_medium=banner&utm_campaign=Practice_Explore_POD_Top_Banner

int getDays(int arr[], int N, int maxWt)
    {
        int sum=0;
        int days=1;
        for ( int i=0; i < N; ++i)
        {
            sum += arr[i];
            if (sum > maxWt)
            {
                days++;
                sum = arr[i];
            }
        }
        return days;

    }
    int leastWeightCapacity(int arr[], int N, int D) {
        int end = accumulate(arr, arr+N, 0);
        int start = *max_element(arr, arr+N);
        int ans=INT_MAX;
        while (end >= start)
        {
            int mid =  (start+ end)/ 2;
            // check id less than D days are possile for mid or lesser than mid value per day
            // then increase mid: start = mid+1
            //else decreas mid
            int days = getDays(arr, N, mid); // mid is max wt allowed
            if ( days <= D)
            {
                ans = mid;
                end = mid-1;
            }
            else
            {
                start = mid+1;
            }
        }
        return ans;

    }

    int runBinarySearch()
    {
        int arr[]{9, 8, 10};
        cout <<  leastWeightCapacity (arr, 3, 3);

    }

#endif // BINARYSEARCH

