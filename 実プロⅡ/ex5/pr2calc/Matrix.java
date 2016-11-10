//package pr2calc;
import java.io.*;

public class Matrix {

	public double m[][];
	public int numOfRow;
	public int numOfColumn;

	public Matrix(){
		this.numOfRow = 0;
		this.numOfColumn = 0;
	}

	public Matrix(double[][] input){
		this.numOfRow=input.length;
		this.numOfColumn = input[0].length;
		this.m = new double[this.getNumOfRow()][this.getNumOfColumn()];
		this.m = input;
	}
	public Matrix(double[] input){
		int i;
		this.numOfRow = 1;
		this.numOfColumn = input.length;
		this.m = new double[this.getNumOfRow()][this.getNumOfColumn()];
		for(i=0;i<this.numOfColumn;i++){
			this.m[0][i]=input[i];
		}
	}
	public Matrix(int row,int column){
		this.numOfRow=row;
		this.numOfColumn=column;
		this.m = new double[this.getNumOfRow()][this.getNumOfColumn()];
	}

	public int getNumOfRow(){
		return this.numOfRow;
	}

	public int getNumOfColumn(){
		return this.numOfColumn;
	}

	public double showsComponentOf(int rowIndex, int columnIndex){
		if(rowIndex > this.numOfColumn || columnIndex > this.numOfColumn){
			System.out.println("");
			System.exit(0);
		}
		return this.m[getNumOfRow()][getNumOfColumn()];
	}

	public void display(){
		int i,j;
		for(i=0;i<this.numOfRow;i++){
			System.out.print("[");
			for(j=0;j<this.numOfColumn;j++){
				System.out.print(" " + this.m[i][j] + " ");
			}
			System.out.println( "]" );
		}
	}


	public double getInnerProduct(Matrix target){
		int i;
		double result=0;
		if(this.numOfColumn == 1){
			System.out.println("Aが列ベクトルなので内積を求められません");
			System.exit(0);
		}
		else if(this.numOfRow == 1 && target.numOfRow == 1 && this.numOfColumn == target.numOfColumn){
			for(i=0;i<this.numOfColumn;i++){
				result += this.m[0][i] * target.m[0][i];
			}
		}
		else if(this.numOfRow == 1 && target.numOfColumn == 1 && this.numOfColumn == target.numOfRow){
			for(i=0;i<this.numOfColumn;i++){
				result += this.m[0][i] * target.m[i][0];
			}
		}
		else{
			System.out.println("内積計算が可能な条件を満たしてません");
			System.exit(0);
		}
		return result;
	}

	public boolean multipliable(Matrix target){
		if(this.numOfColumn == target.numOfRow){
			return true;
		}
		else{
			System.out.println("要素数が計算できる組み合わせとなってません．");
			return false;
		}
	}

	public Matrix multiplyMatrix(Matrix target){
		int i,j,k;
		Matrix result;
		result = new Matrix(this.getNumOfRow(),target.getNumOfColumn());
		for(i=0;i<this.getNumOfRow();i++){
			for(j=0;j<target.getNumOfColumn();j++){
				for(k=0;k<this.getNumOfColumn();k++){
					result.m[i][j]+=this.m[i][k]*target.m[k][j];
				}
				if(result.m[i][j] < 0.00000001  && result.m[i][j] > -0.00000001){
					result.m[i][j] = 0.0;
				}
			}
		}
		return result;
	}

	public Matrix trancepose(){
		int i,j;
		Matrix result;
		result = new Matrix(this.getNumOfColumn(),this.getNumOfRow());
		for(i=0;i<this.getNumOfColumn();i++){
			for(j=0;j<this.getNumOfRow();j++){
				result.m[i][j] = this.m[j][i];
			}
		}
		System.out.println("tranceposed Matrix");
		result.display();
		return result;
	}

	static double convertIntoRadian(double theta){
		return (double)(theta*Math.PI/180);
	}

	public Matrix rotate(double theta ,int number){
		double rad = convertIntoRadian(theta);
		Matrix target,trancepose,result;
		result = new Matrix(2,1);
		double[][]
			radmat={
				{Math.cos(rad),-(Math.sin(rad))},
				{Math.sin(rad),Math.cos(rad)}}
		;
		target = new Matrix(radmat);
		trancepose = this.trancepose();
		System.out.println("Coordinate point (" + number +") after " + theta +"degree");
		if(target.multipliable(trancepose) == true)
			result = (target.multiplyMatrix(trancepose));
		return result;
	}

	public static void main(String[] args) {
		Matrix mat0,mat1;
		double theta1,theta2;
		double[][]
				n0={{2,3},
					{4,5},
					{6,7}
				},

			n1={{10,11},
				{12,13},
				{14,15}
			}
		;

		double[]
				m0 = {-5.0,-5.0},
				m1 = {3,5.196}
		;
		mat0=new Matrix(n0);
		mat1=new Matrix(n1);

		System.out.println("Original matrix");
		mat0.display();
		mat0.trancepose();
		System.out.println("Original matrix");
		mat1.display();
		mat1.trancepose();

		mat0 = new Matrix(m0);
		mat1 = new Matrix(m1);

		System.out.println("Original matrix");
		mat0.display();
		mat1.display();
		theta1 = 45;
		System.out.println("Coordinate point (1) before rotation");
		(mat0.rotate(theta1,1)).display();

		theta2 = -60;
		System.out.println("Coordinate point (2) before rotation");
		(mat1.rotate(theta2,2)).display();


	}
}