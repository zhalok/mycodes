// int n;
// pair<pll,pll> tree[8*sz];
// vll v;

// void build(int idx,int lo,int hi)
// {
// 	// max sum total sum prefix suffix

//     if(lo==hi) {

//     	tree[idx]={{v[lo],v[lo]},{v[lo],v[lo]}};
//     	return ;

// 	}

// 	int mid=(lo+hi)/2;
// 	int left=2*idx+1;
// 	int right=left+1;
// 	build(left,lo,mid);
// 	build(right,mid+1,hi);

//     ll left_max=tree[left].ff.ff;
//     ll left_sum=tree[left].ff.ss;
//     ll left_pref=tree[left].ss.ff;
//     ll left_suf=tree[left].ss.ss;

//     ll right_max=tree[right].ff.ff;
//     ll right_sum=tree[right].ff.ss;
//     ll right_pref=tree[right].ss.ff;
//     ll right_suf=tree[right].ss.ss;

//     ll cross_max=left_suf+right_pref;

// 	ll par_max,par_sum,par_pref,par_suf;

//      par_max=maxx(left_max,maxx(right_max,cross_max));
//      par_sum=left_sum+right_sum;
//      par_pref=maxx(left_pref,left_sum+right_pref);
//      par_suf=maxx(right_suf,right_sum+left_suf);

//     tree[idx]={{par_max,par_sum},{par_pref,par_suf}};

//  }

// void update(int idx,int lo,int hi,int pos,int val)
// {
// 	// max sum total sum prefix suffix
// 	if(lo>pos or hi<pos) return ;

//     if(lo==hi) {

//     	tree[idx]={{val,val},{val,val}};
//     	return ;

// 	}

// 	int mid=(lo+hi)/2;
// 	int left=2*idx+1;
// 	int right=left+1;
// 	update(left,lo,mid,pos,val);
// 	update(right,mid+1,hi,pos,val);

//     ll left_max=tree[left].ff.ff;
//     ll left_sum=tree[left].ff.ss;
//     ll left_pref=tree[left].ss.ff;
//     ll left_suf=tree[left].ss.ss;

//     ll right_max=tree[right].ff.ff;
//     ll right_sum=tree[right].ff.ss;
//     ll right_pref=tree[right].ss.ff;
//     ll right_suf=tree[right].ss.ss;

// 	ll cross_max=left_suf+right_pref;
// 	ll par_max,par_sum,par_pref,par_suf;

// 	par_max=maxx(left_max,maxx(right_max,cross_max));
//     par_sum=left_sum+right_sum;
//     par_pref=maxx(left_pref,left_sum+right_pref);
//     par_suf=maxx(right_suf,right_sum+left_suf);
//     tree[idx]={{par_max,par_sum},{par_pref,par_suf}};
// }

//  pair<pll,pll> query(int idx,int lo,int hi,int qlo,int qhi)
//  {

//     if(qhi<lo or qlo>hi) return {{-inf,-inf},{-inf,-inf}};

//     if(qhi>=hi and qlo<=lo) return tree[idx];

// 	int mid=(lo+hi)/2;
// 	int left=2*idx+1;
// 	int right=left+1;

// //	if(mid<=qlo) return query(right,mid+1,hi,qlo,qhi);
// //	if(mid>=qhi) return query(left,lo,mid,qlo,qhi);

//     pair<pll,pll> left_ans=query(left,lo,mid,qlo,qhi);
// 	pair<pll,pll> right_ans=query(right,mid+1,hi,qlo,qhi);

//     ll left_max=left_ans.ff.ff;
//     ll left_sum=left_ans.ff.ss;
//     ll left_pref=left_ans.ss.ff;
//     ll left_suf=left_ans.ss.ss;

//     ll right_max=right_ans.ff.ff;
//     ll right_sum=right_ans.ff.ss;
//     ll right_pref=right_ans.ss.ff;
//     ll right_suf=right_ans.ss.ss;

//     ll cross_max=left_suf+right_pref;

// 	ll par_max,par_sum,par_pref,par_suf;

//     par_max=maxx(left_max,maxx(right_max,cross_max));
//     par_sum=left_sum+right_sum;
//     par_pref=maxx(left_pref,left_sum+right_pref);
//     par_suf=maxx(right_suf,right_sum+left_suf);

//     return {{par_max,par_sum},{par_pref,par_suf}};

//  }

// int n,q;
// vll v;
// ll tree[4*sz];

// void build_for_sum(int idx,int lo,int hi)
// {
// 	if(lo == hi) {
// 		tree[idx]=v[lo];
// 		return ;
// 	}

// 	int mid = (lo + hi)/2;
// 	int left = 2*idx+1;
// 	int right = 2*idx+2;

// 	build_for_sum(left,lo,mid);
// 	build_for_sum(right,mid+1,hi);
// 	tree[idx]=tree[left]+tree[right];
// }

// void build_for_min(int idx,int lo,int hi)
// {
// 	if(lo==hi)
// 	{
// 		tree[idx]=v[lo];
// 		return ;
// 	}

// 	int mid = (lo+hi)/2;
// 	int left = 2*idx+1;
// 	int right = 2*idx+2;
// 	build_for_min(left,lo,mid);
// 	build_for_min(right,mid+1,hi);
// 	tree[idx]=minn(tree[left],tree[right]);
// }

// void update_for_sum(int idx,int lo,int hi,int upidx,int val)
// {
// 	if(lo>upidx||hi<upidx) return ;
// 	if(lo == hi)
// 	{
// 		// cout<<"Updaate is called"<<endl;
// 		tree[idx]+=val;
// 		return ;
// 	}

// 	int mid = (lo+hi)/2;
// 	int left = 2*idx+1;
// 	int right = 2*idx+2;
// 	update_for_sum(left,lo,mid,upidx,val);
// 	update_for_sum(right,mid+1,hi,upidx,val);

// 	tree[idx] = tree[left]+tree[right];

// }

// void update_for_min(int idx,int lo,int hi,int upidx,int val)
// {

// 	if(lo>upidx||hi<upidx) return ;
// 	if(lo == hi)
// 	{
// 		// cout<<"Updaate is called"<<endl;
// 		tree[idx]=val;
// 		return ;
// 	}

// 	int mid = (lo+hi)/2;
// 	int left = 2*idx+1;
// 	int right = 2*idx+2;
// 	update_for_min(left,lo,mid,upidx,val);
// 	update_for_min(right,mid+1,hi,upidx,val);

// 	tree[idx] = minn(tree[left],tree[right]);

// }

// ll query_of_sum(int idx,int lo,int hi,int qlo,int qhi)
// {
// 	if(qlo>hi||qhi<lo) return 0;
// 	if(qlo<=lo&&qhi>=hi) return tree[idx];

// 	int mid = (lo+hi)/2;
// 	int left = 2*idx+1;
// 	int right = 2*idx+2;
// 	return query_of_sum(left,lo,mid,qlo,qhi) + query_of_sum(right,mid+1,hi,qlo,qhi);

// }

// ll query_for_min(int idx,int lo,int hi,int qlo,int qhi)
// {
//     if(qlo>hi||qhi<lo) return 100001;
// 	if(qlo<=lo&&qhi>=hi) return tree[idx];

// 	int mid = (lo+hi)/2;
// 	int left = 2*idx+1;
// 	int right = 2*idx+2;

// 	return minn(query_for_min(left,lo,mid,qlo,qhi),query_for_min(right,mid+1,hi,qlo,qhi));

// }

// ll query_for_kth_one(int idx,int lo,int hi,int k)
// {
// 	if(lo==hi)
// 	return hi;

//     int mid = (lo+hi)/2;
// 	int left = 2*idx+1;
// 	int right = 2*idx+2;

//     if(tree[right]>=k) return query_for_kth_one(right,mid+1,hi,k);
// 	else return query_for_kth_one(left,lo,mid,k-tree[right]);

// 	return 0;

// }