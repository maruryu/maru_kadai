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
		for(i=0;i<this.numOfColumn;i++){
			this.normalize(i);
			for(j=0;j<this.numOfColumn;j++){
				if(i!=j){
					this.subtractRowFrom(i,j);
				}
			}
		}
	}
	public static void main(String[] args) {
		SimultaneousEquation mat0,mat1;
		
		double[][]
			m0={{2,4,2,8},
				{4,10,3,17},
				{3,7,1,11}}
		;
		
		mat0=new SimultaneousEquation(m0);
		mat0.solveByGaussJordan();
	}
}