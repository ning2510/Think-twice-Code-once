using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class work_用户登录 : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }

    protected void Button1_Click(object sender, EventArgs e)
    {
        String minzi = TextBox1.Text;
        String mima = TextBox2.Text;
        string ConStr = "server=(local);user id=cjn;pwd=123;database=cs";
        SqlConnection con = new SqlConnection(ConStr);
        string SqlStr = "select * from yhdl where zhanghao = '" + minzi + "' and pass = '" + mima + "'" ;
        SqlDataAdapter ada = new SqlDataAdapter(SqlStr, con);
        con.Open();             //打开连接
        DataSet ds = new DataSet();
        ada.Fill(ds);
        con.Close();
        con.Dispose();

        if (ds.Tables[0].Rows.Count <= 0)
        {
            ClientScript.RegisterStartupScript(this.GetType(), "", "<script>alert('您输入的账号或密码有误！');</script>");
        }
        else
        {
            int num = Convert.ToInt32(ds.Tables[0].Rows[0][0]);
            ClientScript.RegisterStartupScript(this.GetType(), "", "<script>alert('登录成功！');</script>");
            Session["id"] = num;
            Response.Redirect("用户管理.aspx?id=" + num);  //传递id值
        }
    }

    protected void Button2_Click(object sender, EventArgs e)
    {
        string zh = TextBox1.Text;
        string pass = TextBox2.Text;
        string ConStr1 = "server=(local);user id=cjn;pwd=123;database=cs";
        SqlConnection con = new SqlConnection(ConStr1);
        string SqlStr = "select * from yhdl where zhanghao = '" + zh + "'";
        SqlDataAdapter ada = new SqlDataAdapter(SqlStr, con);
        con.Open();             //打开连接
        DataSet ds = new DataSet();
        ada.Fill(ds);
        if (ds.Tables[0].Rows.Count <= 0)
        {

            string sqlinsert = "insert into yhdl values ( '" + zh + "','" + pass + "')";
            SqlCommand myCom = new SqlCommand(sqlinsert, con);   //定义SqlCommand对象实例
            myCom.ExecuteNonQuery();     //执行插入语句
            ClientScript.RegisterStartupScript(this.GetType(), "", "<script>alert('恭喜您，注册成功！');</script>");
            con.Close();
            con.Dispose();
            //Response.Redirect("用户登录.aspx");
        }
        else
        {
            ClientScript.RegisterStartupScript(this.GetType(), "", "<script>alert('该账号已被注册！');</script>");
        }
    }
}