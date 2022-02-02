#include "PushRelabel.cpp"

typedef array<ll, 3> Edge;
vector<Edge> gomoryHu(int N, vector<Edge> ed) {
	vector<Edge> tree;
	vi par(N);
	rep(i,1,N) {
		PushRelabel D(N); // Dinic also works
		for (Edge t : ed) D.addEdge(t[0], t[1], t[2], t[2]);
		tree.push_back({i, par[i], D.calc(i, par[i])});
		rep(j,i+1,N)
			if (par[j] == par[i] && D.leftOfMinCut(j)) par[j] = i;
	}
	return tree;
}