using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class work_Delete : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        if (Session["id"] == null)
        {
            Response.Redirect("jiemian.aspx");
        }
    }

    protected void Button2_Click(object sender, EventArgs e)
    {
        string zh = TextBox1.Text;
        string ConStr = "server=(local);user id=cjn;pwd=123;database=cs";
        SqlConnection con = new SqlConnection(ConStr);
        string SqlStr = "select * from yhdl where zhanghao='" + zh + "'";   //要执行的sql语句
        SqlDataAdapter ada = new SqlDataAdapter(SqlStr, con);
        con.Open();
        DataSet ds = new DataSet();
        ada.Fill(ds);
        if (ds.Tables[0].Rows.Count > 0) //表里面是否有行
        {
            string sqlinsert = "delete from yhdl where zhanghao= '" + zh + "'";
            SqlCommand myCom = new SqlCommand(sqlinsert, con);   //定义SqlCommand对象实例
            myCom.ExecuteNonQuery();     //执行插入语句
            //ClientScript.RegisterStartupScript(this.GetType(), "", "<script>alert('用户删除成功！');</script>");
            con.Close();
            con.Dispose();
            //Response.Redirect("write.aspx");

            string ConStr1 = "server=(local);user id=cjn;pwd=123;database=cs";
            SqlConnection con1 = new SqlConnection(ConStr1);
            string sqlinsert1 = "delete from dianzan where username= '" + zh + "'";
            SqlCommand myCom1 = new SqlCommand(sqlinsert1, con1);   //定义SqlCommand对象实例
            con1.Open();
            myCom1.ExecuteNonQuery();     //执行插入语句
            ClientScript.RegisterStartupScript(this.GetType(), "", "<script>alert('用户删除成功！');</script>");
            con1.Close();
            con1.Dispose();
        }
        else ClientScript.RegisterStartupScript(this.GetType(), "", "<script>alert('没有该用户！');</script>");
    }
}