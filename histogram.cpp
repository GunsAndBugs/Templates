/*

    Histogram problem. 
    Given N length Histogram. Find the max area rectangle that can be formed. 
    Time: O(n)
    Space: O(n)

*/

struct histogram{
	vector < LL > h;
	stack < LL > Stack;
	
	LL MaxArea;
	
	histogram(){
		MaxArea = 0;
	}
	
	
	void take(LL a){ h.pb(a); }
	
	LL CalculateMaxArea(){
		
		MaxArea = 0;
		for(LL i = 0 ; i<sz(h) ; i++){
			if( Stack.empty() || h[Stack.top()]<=h[i] ) Stack.push(i);
			else{
				
				while( !Stack.empty() && ( h[Stack.top()] > h[i]) ){
					LL minLen = h[Stack.top()]; Stack.pop();
					LL area;
					if( Stack.empty() ) area = minLen*i;
					else area = minLen*(i - Stack.top() - 1);
					MaxArea = max(MaxArea , area); 
				}
				Stack.push(i);
			}
			DEBUG(h[i]);
		}
		
		while(!Stack.empty()){
					LL minLen = h[Stack.top()]; Stack.pop();
					LL area;
					
					if( Stack.empty() ) area = minLen*sz(h);
					else area = minLen*(sz(h) - Stack.top() - 1);
					MaxArea = max(MaxArea , area); 
		}
		
		return MaxArea;
	}
	
	void clear(){
		h.clear();
	}
};