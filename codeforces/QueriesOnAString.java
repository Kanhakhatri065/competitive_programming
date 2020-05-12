import java.util.*;
public class QueriesOnAString{
	public static void main(String []args){
		
		java.util.Scanner scan=new java.util.Scanner(System.in);
		String str=scan.next();
		int cases=scan.nextInt();
		for(int j=1;j<=cases;j++){
			int l=scan.nextInt();
			int r=scan.nextInt();
			int k=scan.nextInt();
			k=k%(r-l+1);
			String strFinal=str;
			String strIn1,strIn2;
			strIn1=strFinal.substring(l-1,r-k);
			//System.out.println(strIn1);
			strIn2=strFinal.substring(r-k,r);
			
			//System.out.println(strIn2);
			strFinal=strFinal.substring(0,l-1)+strIn2+strIn1+strFinal.substring(r);
			str=strFinal;
		}
			System.out.println(str);
		
	}
}