vi topoSort(const vector<vi>& gr) {
	vi indeg(sz(gr)), ret;
	for (auto& li : gr) for (int x : li) indeg[x]++;
	queue<int> q; // use priority_queue for lexic. largest ans.
	rep(i,0,sz(gr)) if (indeg[i] == 0) q.push(i);
	while (!q.empty()) {
		int i = q.front(); // top() for priority queue
		ret.push_back(i);
		q.pop();
		for (int x : gr[i])
			if (--indeg[x] == 0) q.push(x);
	}
	return ret;
}