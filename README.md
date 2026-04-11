# Games101:作业统计

## 作业0：虚拟机的使用

安装虚拟机后，发现虚拟机中vscode无法打开，且非常卡顿。经过考虑后决定在本地环境下安装环境。

1.决定使用vs2022作为开发环境

2.浏览器下载并安装Eigen和opencv

3.在visual stadio 2022配置Eigen和opencv

作业内容：给定一个点P=(2,1), 将该点绕原点先逆时针旋转45◦，再平移(1,2), 计算出变换后点的坐标（要求用齐次坐标进行计算）。

代码如下：

```c++
#include <cmath>
#include <Eigen/Dense>
#include <Eigen/Core>
#include <iostream>

int main()
{
	float pi = acos(-1.0f);

	float quarterpi = pi / 4.0f;

	std::cout << std:: cos(quarterpi) << std::endl;

	std::cout << std:: sin(quarterpi) << std::endl;

	float c = cos(quarterpi);
	float s = sin(quarterpi);

	Eigen::Vector3f v(2.0f, 1.0f, 1.0f);
	
	Eigen::Matrix3f r;
	r << c, -s, 0.0f,
		s, c, 0.0f,
		0.0f, 0.0f, 1.0f;

	std::cout << r * v << std::endl;

	Eigen::Matrix3f t;
	t << 1.0f, 0.0f, 1.0f,
		0.0f, 1.0f, 2.0f,
		0.0f, 0.0f, 1.0f;

	std::cout << t * r * v << std::endl;

	return 0;
}
```

输出结果：

```c++
0.707107
0.707107
0.707107
 2.12132
       1
1.70711
4.12132
      1
```

​                                                                                                                                                                                                                                               完成日期：26.04.11
