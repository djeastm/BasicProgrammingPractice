import java.io.*;
import java.util.*;
public class UVA00272 {

	public static void main(String[] args) throws IOException {
		// Use BufferedReader rather than RandomAccessFile; it's much faster
		BufferedReader f = new BufferedReader(new FileReader("a.in"));
		// input file name goes above
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
				"a.out")));
		// Use StringTokenizer vs. readLine/split -- lots faster
		StringTokenizer st = new StringTokenizer(f.readLine());
		// Get line, break into tokens
		String s1 = st.nextToken(); // first string
		st = new StringTokenizer(f.readLine());
		String s2 = st.nextToken(); // second string
		out.println(s1);
		out.close(); // close the output file
	}

}
