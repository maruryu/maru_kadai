//package pr2calc;
import java.io.*;

public class SimultaneousEquation extends Matrix{
	double[] answers;
	
	public SimultaneousEquation(){
		super();
	}
	
	public SimultaneousEquation(double[][] input){
		super(input);
	}

	public SimultaneousEquation(double[] input){
		super(input);
	}

	public SimultaneousEquation(int row,int column){
		super(row,column);
	}
	
	public void normalize(int row){
		double num=this.m[row][row];
		int j;
		for(j=0;j<this.numOfColumn;j++){
			this.m[row][j]/=num;
		}
		
		System.out.println(row + "s"+ row + "—ñ–Ú‚ª1‚Æ‚È‚é‚æ‚¤‚ÉŠ„‚èA‘¼‚Ìs‚Ì"+row+"—ñ–Ú‚ª0‚Æ‚È‚é‚æ‚¤‚Éˆø‚­");
	}
	
	public void subtractRowFrom(int row1,int row2){
		double num=this.m[row2][row1]/this.m[row1][row1];
		int i;
		for(i=0;i<this.numOfColumn;i++){
			this.m[row2][i]=this.m[row2][i]-(this.m[row1][i]*num);
		}
	}
	
	public void solveByGaussJordan(){
		int i,j;
		this.answers = new double[this.numOfRow];
		for(i=0;i<(this.numOfColumn-1);i++){
			this.normalize(i);
			for(j=0;j<this.numOfRow;j++){
				if(i!=j){
					this.subtractRowFrom(i,j);
				}
			}
			this.display();
		}
		for(i=0;i<this.numOfRow;i++){
			this.answers[i]=this.m[i][(this.numOfColumn)-1];
		}
	}
	public void ansDisplay(){
		int i,j=0;
		System.out.println("Œ‹‰Ê");
		for(i=0;i<this.numOfRow;i++){
			j=i+1;
			System.out.print("x" + j + " = " + this.answers[i]);
			if(i!=(this.numOfRow)-1){
				System.out.print("   ,");
			}
		}
		System.out.println(".");
	}
	public static void main(String[] args) {
		int i,j;
		SimultaneousEquation mat0,mat1;
		
		double[][]
			m0={{2,1,3,4,2},
			{3,2,5,2,12},
			{3,4,1,-1,4},
			{-1,-3,1,3,-1}},
			
			m1={{4,3,2,1,4},
			{-2,4,-6,8,-34},
			{3,2,-3,-3,-4},
			{12,6,7,5,18.5}}
		;
		
		mat0=new SimultaneousEquation(m0);
		mat0.solveByGaussJordan();
		mat0.ansDisplay();
	}
}