import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Main {
	
	public void Solve() throws IOException {
		int i;
		int n = nextInt();
		BigInteger[] P = new BigInteger[n];
		for (i = 0; i < n; i++)
			P[i] = nextBigInteger();
		BigInteger[] Lcm = new BigInteger[1 << n];
		int[] ctz = new int[1 << n];
		int[] ppc = new int[1 << n];
		for (i = 0; i < n; i++)
			ctz[1 << i] = i;
		Lcm[0] = BigInteger.ONE;
		ppc[0] = 0;
		BigInteger fz = BigInteger.ZERO;
		BigInteger fm;
		for (i = 1; i < 1 << n; i++) {
			int la = i & (-i);
			int id = ctz[la];
			ppc[i] = ppc[i ^ la] + 1;
			Lcm[i] = P[id].divide(Lcm[i ^ la].gcd(P[id])).multiply(Lcm[i ^ la]);
		}
		fm = Lcm[(1 << n) - 1];
		for (i = 1; i < 1 << n; i++) {
			BigInteger add = fm.divide(Lcm[i]);
			if (ppc[i] % 2 == 1) fz = fz.add(add);
			else fz = fz.subtract(add);
		}
		BigInteger g = fz.gcd(fm);
		fz = fz.divide(g);
		fm = fm.divide(g);
		writer.println(fz);
		writer.println(fm);
		flh();
	}
	
	public static void main(String[] args) throws IOException {
		new Main().run();
	}
	
	BufferedReader	reader;
	StringTokenizer	tokenizer;
	PrintWriter			writer;
	
	public void flh() {
		writer.flush();
	}
	
	public void run() {
		try {
			reader = new BufferedReader(new InputStreamReader(System.in));
			writer = new PrintWriter(System.out);
			tokenizer = null;
			while (hasNext())
				Solve();
			reader.close();
			writer.flush();
			writer.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}
	
	boolean hasNext() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			String nextLine = reader.readLine();
			if (nextLine == null) return false;
			tokenizer = new StringTokenizer(nextLine);
		}
		return true;
	}
	
	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}
	
	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}
	
	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
	
	String nextLine() throws IOException {
		return reader.readLine();
	}
	
	String nextToken() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}
	
	BigInteger nextBigInteger() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return new BigInteger(tokenizer.nextToken());
	}
}
