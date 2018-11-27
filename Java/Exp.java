import org.python.core.PyFunction;
import org.python.core.PyObject;
import org.python.util.PyInterpreter;

public class Exp{
	public static void main(String[] args) {
		PythonInterpreter itp = new PyInterpreter();
		itp.execfile("exp.py");

	}
}