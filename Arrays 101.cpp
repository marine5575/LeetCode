/*******************************/
// Squares of a Sorted Array
// 핵심: Two Pointer & 문제 잘 읽기! 
/*******************************/
#if 0

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int sz = nums.size();	// 벡터 크기 잡기 위함 
        vector<int> square(sz);	// 제곱수가 들어갈 벡터 

		// 절댓값으로 바꾸기 
        for(int i = 0; i < sz; i++) {
            nums[i] = abs(nums[i]);
        }

        int l = 0, r = sz - 1, pt = sz - 1;	// 왼쪽, 오른쪽 화살표, 벡터에 넣을 위치 

		// 불변식: 왼쪽 화살표는 오른쪽 화살표보다 왼쪽에 있다 & pt는 범위를 벗어나지 않음 
        while(l <= r && pt >= 0) {
            if(nums[l] < nums[r]) {
                square[pt--] = nums[r] * nums[r--];
            }
            else {
                square[pt--] = nums[l] * nums[l++];
            }
        }
        
        return square;
    }
};
#endif


/*******************************/
// <<< 컨셉 첨에 못 잡음 >>> 
// Remove Element
// 핵심: Two Pointer => 지울 때 다 옮기지 말고 하나만 옮기자! 
/*******************************/
#if 0

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.size() == 0) return 0;

        int wp = 0;	// 놓을 곳 

        for (int i = 0; i < nums.size(); i++) {
        	// 스킵할 숫자가 아닌 경우, 앞으로 땡겨온다 
            if (nums[i] != val) nums[wp++] = nums[i];
        }
        
        return wp;
    }
};
#endif


/*******************************/
// Remove Duplicates from Sorted Array
// 핵심: Two Pointer => 지울 때 다 옮기지 말고 하나만 옮기자! 
/*******************************/
#if 0

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        
        int dupCnt = 0, sz = nums.size();	// 중복된 것의 총 개수, 벡터 크기 

        for (int i = 1; i < sz; i++) {
        	// 지금 도착한 숫자와 이전 숫자가 다를 경우 
            if (nums[i] != nums[i - 1]) nums[i - dupCnt] = nums[i];
            // 같을 경우 
            else dupCnt++;
        }
        
        return sz - dupCnt;
    }
};
#endif


/*******************************/
// Check If N and Its Double Exist
// 핵심: 이진탐색 
/*******************************/
#if 0

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(), arr.end());	// 오름차순 

        int zeroCnt = 0;	// 0의 개수 

        for (int i = 0; i < arr.size(); i++) {
        	// 0이 아닐 때 
            if (arr[i]) {
                int result = binSearch(arr, arr[i] * 2);	// arr[i] * 2를 찾은 위치 

				// 찾지 못했거나 같은 위치일 때 
                if (result != -1 && result != i) return true;
            }
            else zeroCnt++;
        }

        return zeroCnt >= 2;
    }
    
    int binSearch(vector<int>& arr, int val) {
    	// arr = 찾을 배열, val = 찾는 값 
    	
        int s = 0, e = arr.size() - 1;

        if (arr[s] == val) return s;
        if (arr[e] == val) return e;

        while (s < e - 1) {
            int mid = s + (e - s) / 2;

            if (arr[mid] < val)  s= mid;
            else e = mid;
        }

        if (arr[e] == val) return e;
        else return -1;
    }
};
#endif


/*******************************/
// Third Maximum Number
// 핵심: unique하게 값을 뽑아내기
// 		=> 1. set 사용  2. unique(vec.begin(), vec.end())
// 			-> 2의 경우 unique는 앞에 고유값들 몰려있고, 뒤에 쓰레기값 몰려있음.
// 				쓰레기값의 시작지점을 return 
/*******************************/
#if 0

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end());	// 오름차순 
        nums.erase(unique(nums.begin(), nums.end()), nums.end());	// 중복제거 

        return nums.size() < 3 ? nums[nums.size() - 1] : nums[nums.size() - 3];
    }
};
#endif


/*******************************/
// <<< 이거 좀 어려운 듯? >>> 
// Find All Numbers Disappeared in an Array
// 핵심: 아이디어 
/*******************************/
#if 0

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            int to = abs(nums[i]) - 1;	// 찾아갈 위치 

			// 이미 찾아갔으면 그대로, 안 찾아갔다면 방문 체크 
            nums[to] = nums[to] < 0 ? nums[to] : -nums[to];
        }

        vector<int> ans;

        for(int i = 0; i < nums.size(); i++) {
        	// 방문한 적 없는 위치일 때 
            if(nums[i] > 0) ans.push_back(i + 1);
        }
        
        return ans;
    }
};
#endif
