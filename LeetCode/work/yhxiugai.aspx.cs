using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class work_yhxiugai : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        if (Session["id"] == null)
        {
            Response.Redirect("jiemian.aspx");
        }
        int did = Convert.ToInt32(Request["id"]);
        int id = did;
        string neirong = TextBox1.Text.ToString();  //要插入纸条的内容
        string ConStr = "server=(local);user id=cjn;pwd=123;database=cs";

        SqlConnection con1 = new SqlConnection(ConStr);
        string SqlStr = "select * from yhdl where id='" + id + "'";   //要执行的sql语句
        SqlDataAdapter ada = new SqlDataAdapter(SqlStr, con1);
        con1.Open();
        DataSet ds = new DataSet();
        ada.Fill(ds);
        username.Text = ds.Tables[0].Rows[0][1].ToString();
    }

    protected void Button1_Click(object sender, EventArgs e)
    {
        int cn = Convert.ToInt32(Request["cnt"]);
        //string neirong = Request["nr"].ToString();
        string nr = TextBox1.Text.ToString();
        string ConStr = "server=(local);user id=cjn;pwd=123;database=cs";
        SqlConnection con = new SqlConnection(ConStr);
        con.Open();
        string sqlxg = "update dianzan set neirong='" + nr + "' where cnt='" + cn + "'";
        SqlCommand myCom = new SqlCommand(sqlxg, con);   //定义SqlCommand对象实例
        myCom.ExecuteNonQuery();     //执行插入语句
        con.Close();
        con.Dispose();

        /*SqlConnection con1 = new SqlConnection(ConStr);
        con1.Open();
        string sqlxg1 = "update pinglun set neirong='" + nr + "' where neirong='" + cn + "'";
        SqlCommand myCom1 = new SqlCommand(sqlxg1, con1);   //定义SqlCommand对象实例
        myCom1.ExecuteNonQuery();     //执行插入语句
        con1.Close();
        con1.Dispose();*/

        ClientScript.RegisterStartupScript(this.GetType(), "", "<script>alert('修改成功！');</script>");
    }


    protected void Button3_Click(object sender, EventArgs e)
    {
        int did = Convert.ToInt32(Request["id"]);
        Response.Redirect("用户管理.aspx?id=" + did);
    }

    protected void Button2_Click(object sender, EventArgs e)
    {
        int did = Convert.ToInt32(Request["id"]);
        Response.Redirect("用户查看.aspx?id=" + did);
    }
}