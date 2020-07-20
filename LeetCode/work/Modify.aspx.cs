using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class work_Modify : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        if (Session["id"] == null)
        {
            Response.Redirect("jiemian.aspx");
        }
    }

    protected void Button1_Click(object sender, EventArgs e)
    {
        string zh = TextBox1.Text.ToString();
        string ps = TextBox2.Text;
        string ConStr = "server=(local);user id=cjn;pwd=123;database=cs";
        SqlConnection con = new SqlConnection(ConStr);
        con.Open();
        string sqlxg = "update yhdl set pass='" + ps + "' where zhanghao='" + zh + "'";
        SqlCommand myCom = new SqlCommand(sqlxg, con);   //定义SqlCommand对象实例
        myCom.ExecuteNonQuery();     //执行插入语句
        ClientScript.RegisterStartupScript(this.GetType(), "", "<script>alert('已修改密码');</script>");
        con.Close();
        con.Dispose();
    }
}