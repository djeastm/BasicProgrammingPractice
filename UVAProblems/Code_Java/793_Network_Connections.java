import java.io.*;
import java.util.*;

//Union-Find Disjoint Sets Library written in OOP manner, using both path compression and union by rank heuristics
class UnionFind { // OOP style
	private Vector<Integer> p, rank, setSize;
	private int numSets;

	public UnionFind(int N) {
		p = new Vector<Integer>(N);
		rank = new Vector<Integer>(N);
		setSize = new Vector<Integer>(N);
		numSets = N;
		for (int i = 0; i < N; i++) {
			p.add(i);
			rank.add(0);
			setSize.add(1);
		}
	}

	public int findSet(int i) {
		if (p.get(i) == i)
			return i;
		else {
			int ret = findSet(p.get(i));
			p.set(i, ret);
			return ret;
		}
	}

	public Boolean isSameSet(int i, int j) {
		return findSet(i) == findSet(j);
	}

	public void unionSet(int i, int j) {
		if (!isSameSet(i, j)) {
			numSets--;
			int x = findSet(i), y = findSet(j);
			// rank is used to keep the tree short
			if (rank.get(x) > rank.get(y)) {
				p.set(y, x);
				setSize.set(x, setSize.get(x) + setSize.get(y));
			} else {
				p.set(x, y);
				setSize.set(y, setSize.get(y) + setSize.get(x));
				if (rank.get(x) == rank.get(y))
					rank.set(y, rank.get(y) + 1);
			}
		}
	}

	public int numDisjointSets() {
		return numSets;
	}

	public int sizeOfSet(int i) {
		return setSize.get(findSet(i));
	}
}

public class Main {

	public static void main(String[] args) {
		// Use BufferedReader rather than RandomAccessFile; it's much faster
		// BufferedReader f = new BufferedReader(new FileReader("a.in"));
		// input file name goes above
		// PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
		// "a.out")));
		Main myWork = new Main(); // create a dinamic instance
		myWork.Begin(); // the true entry point
	}

	void Begin() {

		try {

			// BufferedReader f = new BufferedReader(new
			// InputStreamReader(System.in));
			BufferedReader f = new BufferedReader(new FileReader("793.in"));

			while (f.ready()) {

				int TC = Integer.parseInt(f.readLine());
				f.readLine();

				int d = 0;
				while (TC-- != 0) {
					int count, a, b;
					int successful = 0, unsuccessful = 0;
					count = Integer.parseInt(f.readLine());
					UnionFind uf = new UnionFind(count);
					char t; // type, connection or query
					String line;
					while (f.ready() && !(line = f.readLine()).equals("\n")
							&& (line.split(" ").length == 3)) {
						String[] input = line.split(" ");
						t = input[0].charAt(0);
						a = Integer.parseInt(input[1]);
						b = Integer.parseInt(input[2]);
						--a;
						--b;
						if (t == 'c')
							uf.unionSet(a, b);
						else if (t == 'q') {
							if (uf.isSameSet(a, b))
								++successful;
							else
								++unsuccessful;
						}
					}

					if (d > 0)
						System.out.println();
					++d;
					System.out.printf("%d,%d\n", successful, unsuccessful);
				}
			}

		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
