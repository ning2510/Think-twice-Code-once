using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class work_管理登录 : System.Web.UI.Page
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
        string SqlStr = "select * from gldl where id = '" + minzi + "' and  pass = '" + mima + "'";
        SqlDataAdapter ada = new SqlDataAdapter(SqlStr, con);
        con.Open();             //打开连接
        DataSet ds = new DataSet();
        ada.Fill(ds);

        if (ds.Tables[0].Rows.Count <= 0)
        {
            ClientScript.RegisterStartupScript(this.GetType(), "", "<script>alert('您输入的账号或密码有误！');</script>");
        }
        else
        {
            ClientScript.RegisterStartupScript(this.GetType(), "", "<script>alert('登录成功！');</script>");
            Session["id"] = 0;
            Response.Redirect("write.aspx");
        }
    }

    protected void Button2_Click(object sender, EventArgs e)
    {
        TextBox1.Text = "";
        TextBox2.Text = "";
    }
}