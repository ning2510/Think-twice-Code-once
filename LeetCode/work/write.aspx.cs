using System;
using System.Collections.Generic;
using System.Data;
using System.Data.OleDb;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class work_write : System.Web.UI.Page
{
    
    protected void Page_Load(object sender, EventArgs e)
    {
        if (Session["id"] == null)
        {
            Response.Redirect("jiemian.aspx");
        }
        if (!IsPostBack)
        {
            num.Text = "1";
            repdatabind();
        }
    }

    public void repdatabind()
    {
        string ConStr = "server=(local);user id=cjn;pwd=123;database=cs";
        SqlConnection con = new SqlConnection(ConStr);
        string SqlStr;
        SqlStr = "select * from dianzan where 1=1 order by id asc"; //根据id的值按升序排序
        SqlDataAdapter ada = new SqlDataAdapter(SqlStr, con);
        con.Open();             //打开连接
        DataSet ds = new DataSet();

        ada.Fill(ds, "dz");   //dz：表的名字
        PagedDataSource pds = new PagedDataSource();
        pds.DataSource = ds.Tables["dz"].DefaultView;   //DefaultView:相当于一个数据库中的视图
        pds.AllowPaging = true;     //允许分页
        pds.PageSize = 3;   //单页显示项数

        int curpage = Convert.ToInt32(num.Text);
        this.BtnDown.Enabled = true;    //下一页功能可用
        this.BtnUp.Enabled = true;      //上一页功能可用
        pds.CurrentPageIndex = curpage - 1;     //当前页
        if (curpage == 1)   //第一页时 上一页按钮不可用
        {
            this.BtnUp.Enabled = false;
        }
        if (curpage == pds.PageCount)   //最后一页时 下一页按钮不可用
        {
            this.BtnDown.Enabled = false;
        }
        this.Repeater1.DataSource = pds;
        this.Repeater1.DataBind();
    }

    protected void BtnUp_Click(object sender, EventArgs e)
    {
        this.num.Text = Convert.ToString(Convert.ToInt32(num.Text) - 1);
        repdatabind();
    }

    protected void BtnDown_Click(object sender, EventArgs e)
    {
        this.num.Text = Convert.ToString(Convert.ToInt32(num.Text) + 1);
        repdatabind();
    }



    protected void Button2_Click(object sender, EventArgs e)
    {
        int id = 0;
        string username = "Admin";
        string neirong = TextBox1.Text.ToString();  //要插入纸条的内容
        string ConStr = "server=(local);user id=cjn;pwd=123;database=cs";
        SqlConnection con = new SqlConnection(ConStr);
        con.Open();
        string zfuser = " ";
        int redu = 0;    //初始化热度值
        string sqlcr = "INSERT INTO dianzan VALUES( '" + id + "','" + neirong + "','" + redu + "','" + username + "','" + zfuser + "')";    //INSERT语句插入
        SqlCommand myCom = new SqlCommand(sqlcr, con);   //定义SqlCommand对象实例
        myCom.ExecuteNonQuery();     //执行插入语句
        ClientScript.RegisterStartupScript(this.GetType(), "", "<script>alert('成功发布留言!');</script>");
        con.Close();
        con.Dispose();
        Response.Redirect("write.aspx");
    }

    protected void Repeater1_ItemDataBound(object sender, RepeaterItemEventArgs e)
    {
        //Button p = (Button)Repeater1.Items[id0].FindControl("Button3");
        Button q = (Button)e.Item.FindControl("Button3");
        int p = Convert.ToInt32(q.CommandArgument);
        //string p = q.CommandArgument.ToString();
        //判断里层repeater处于外层repeater的哪个位置（ AlternatingItemTemplate，FooterTemplate，
        //HeaderTemplate，，ItemTemplate，SeparatorTemplate）
        if (e.Item.ItemType == ListItemType.Item || e.Item.ItemType == ListItemType.AlternatingItem)
        {
            Repeater rep = e.Item.FindControl("Repeater2") as Repeater;//找到里层的repeater对象
            DataRowView rowv = (DataRowView)e.Item.DataItem;//找到分类Repeater关联的数据项 
            //int typeid = Convert.ToInt32(rowv["qtid"]); //获取填充子类的id 

            string ConStr = "server=(local);user id=cjn;pwd=123;database=cs";
            SqlConnection con = new SqlConnection(ConStr);
            string SqlStr;
            SqlStr = "select top 10 * from pinglun where neirong='" + p + "'";
            SqlDataAdapter ada = new SqlDataAdapter(SqlStr, con);
            con.Open();             //打开连接
            DataSet ds = new DataSet();
            ada.Fill(ds);
            rep.DataSource = ds;
            rep.DataBind();
        }
    }

    protected void Repeater1_ItemCommand(object source, RepeaterCommandEventArgs e)
    {
        int cnt = Convert.ToInt32(e.CommandArgument);
        //string neirong = e.CommandArgument.ToString();
        string ConStr = "server=(local);user id=cjn;pwd=123;database=cs";
        SqlConnection con = new SqlConnection(ConStr);
        string SqlStr = "select * from dianzan where cnt='" + cnt + "'";   //要执行的sql语句
        SqlDataAdapter ada = new SqlDataAdapter(SqlStr, con);
        con.Open();
        DataSet ds = new DataSet();
        ada.Fill(ds);
        if (e.CommandName == "add")
        {
            int redu = Convert.ToInt32(ds.Tables[0].Rows[0][2]) + 1;    //获取第一张表中第一行第二列
            string sqlxg = "update dianzan set redu='" + redu + "' where cnt='" + cnt + "'";
            SqlCommand myCom = new SqlCommand(sqlxg, con);   //定义SqlCommand对象实例
            myCom.ExecuteNonQuery();     //执行插入语句
            ClientScript.RegisterStartupScript(this.GetType(), "", "<script>alert('已发布留言！');</script>");
            con.Close();
            con.Dispose();
            Response.Redirect("write.aspx");
        }
        else if (e.CommandName == "delete")
        {
            if (ds.Tables[0].Rows.Count > 0) //表里面是否有行
            {
                string sqlinsert = "delete from dianzan where cnt= '" + cnt + "'";
                SqlCommand myCom = new SqlCommand(sqlinsert, con);   //定义SqlCommand对象实例
                myCom.ExecuteNonQuery();     //执行插入语句
                ClientScript.RegisterStartupScript(this.GetType(), "", "<script>alert('已删除该留言！');</script>");
                con.Close();
                con.Dispose();
                Response.Redirect("write.aspx");
            }
        }
        else if (e.CommandName == "pinglun")
        {
            /*string ConStr1 = "server=(local);user id=cjn;pwd=123;database=cs";
            SqlConnection con1 = new SqlConnection(ConStr1);
            string SqlStr1 = "select * from dianzan";   //要执行的sql语句
            SqlDataAdapter ada1 = new SqlDataAdapter(SqlStr1, con1);
            con1.Open();
            DataSet ds1 = new DataSet();
            ada1.Fill(ds1);
            int x = -1;
            for (int i = 0; i < ds1.Tables[0].Rows.Count; i++)
            {
                string p1 = ds1.Tables[0].Rows[i][1].ToString();    //内容
                int p2 = Convert.ToInt32(ds1.Tables[0].Rows[i][2]);  //热度
                string p3 = ds1.Tables[0].Rows[i][3].ToString();    //用户名
                if (p1 == neirong && p2 == m1 && p3 == m2)
                {
                    x = i;
                    break;
                }
            }
            TextBox aaa = (TextBox)Repeater1.Items[x].FindControl("TextBox2");
            string pl = aaa.Text.ToString();*/

            string m2 = "Admin";    //评论者用户名

            TextBox bbb = (TextBox)e.Item.FindControl("TextBox2");
            string pl = bbb.Text.ToString();
            SqlConnection con2 = new SqlConnection(ConStr);
            con2.Open();
            string sqlcr = "INSERT INTO pinglun VALUES( '" + pl + "','" + m2 + "','" + cnt + "')";    //INSERT语句插入
            SqlCommand myCom = new SqlCommand(sqlcr, con2);   //定义SqlCommand对象实例
            myCom.ExecuteNonQuery();     //执行插入语句
            ClientScript.RegisterStartupScript(this.GetType(), "", "<script>alert('评论成功!');</script>");
            con2.Close();
            con2.Dispose();
            Response.Redirect("write.aspx");
        }
        else if(e.CommandName == "xiugai")
        {
            Response.Redirect("xiugai.aspx?cnt=" + cnt);
        }
        else if(e.CommandName == "zhuanfa")
        {
            int id = 0;
            string username = "Admin";
            string neirong = ds.Tables[0].Rows[0][1].ToString();  //要插入纸条的内容
            string ConStr1 = "server=(local);user id=cjn;pwd=123;database=cs";
            SqlConnection con1 = new SqlConnection(ConStr1);
            con1.Open();
            int redu = 0;    //初始化热度值
            string zfuser = "转自：" + ds.Tables[0].Rows[0][3].ToString();
            string sqlcr = "INSERT INTO dianzan VALUES( '" + id + "','" + neirong + "','" + redu + "','" + username + "','" + zfuser + "')";    //INSERT语句插入
            SqlCommand myCom = new SqlCommand(sqlcr, con1);   //定义SqlCommand对象实例
            myCom.ExecuteNonQuery();     //执行插入语句
            ClientScript.RegisterStartupScript(this.GetType(), "", "<script>alert('转发成功!');</script>");
            con1.Close();
            con1.Dispose();
            Response.Redirect("write.aspx");
        }
    }

    protected void Button1_Click(object sender, EventArgs e)
    {
        try
        {
            string pathc = Server.MapPath("excel");
            string excelpath = System.IO.Path.GetExtension(FileUpload1.FileName).ToLower();
            FileUpload1.PostedFile.SaveAs(pathc + FileUpload1.FileName);
            Session["txt"] = FileUpload1.FileName;
            string path = Server.MapPath("excel") + Session["txt"].ToString();
            string constring = @"Provider=Microsoft.Jet.OLEDB.4.0;Data Source=" + path + "; Extended Properties=Excel 8.0;";
            OleDbConnection con = new OleDbConnection(constring);
            OleDbDataAdapter da = new OleDbDataAdapter("select * from [dianzan]", con);
            DataSet ds = new DataSet();
            da.Fill(ds);
            int nn = ds.Tables[0].Rows.Count;
            
            for (int i = 0; i < ds.Tables[0].Rows.Count; i++)
            {
                int did1 = 0;
                string nr = ds.Tables[0].Rows[i][1].ToString();
                int ru = Convert.ToInt32(ds.Tables[0].Rows[i][2]);
                string un = ds.Tables[0].Rows[i][3].ToString();
                string zfuser = " ";
                string constr = "server=(local); user id=cjn; pwd=123; database=cs";
                SqlConnection mycon = new SqlConnection(constr);
                string sqlin = "insert into dianzan values('" + did1 + "','" + nr + "','" + ru + "','" + un + "','" + zfuser + "')";
                SqlCommand com = new SqlCommand(sqlin, mycon);
                mycon.Open();
                com.ExecuteNonQuery();
                ClientScript.RegisterStartupScript(this.GetType(), "", "<script>alert('恭喜您，添加成功！');</script>");
                mycon.Close();
                mycon.Dispose();
            }
            Response.Redirect("write.aspx");
        }
        catch (Exception ey)
        {
            ClientScript.RegisterStartupScript(this.GetType(), "", "<script>alert('请正确选择excel文件！');</script>");
        }
    }
}