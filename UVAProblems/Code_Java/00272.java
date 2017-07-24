import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) {
		// Use BufferedReader rather than RandomAccessFile; it's much faster
		// BufferedReader f = new BufferedReader(new FileReader("a.in"));
		// input file name goes above
		// PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
		// "a.out")));
		Main myWork = new Main();  // create a dinamic instance
        myWork.Begin();            // the true entry point
	}

	void Begin() {		
		
		try {
			
			BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
//			BufferedReader f = new BufferedReader(new StringReader("\"To be or not to be,\" quoth the Bard, \"that"));

			boolean first = true;
			
			while (f.ready()) {
				char ch = (char) f.read();
				if (ch == '"') {
					if (first) {
						System.out.printf("%s", "``");
						first = false;
					} else {
						System.out.printf("%s", "''");
						first = true;
					}
				} else {
					System.out.printf("%c", ch);
				}
			}
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
